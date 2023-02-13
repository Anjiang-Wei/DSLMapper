import sys
import re

# 1d00000000000008 -> LOC_PROC
# 1e00000000000000 -> SYSTEM_MEM
charmap = {}

map_replicate = []
sharding = []
slicing = []
map_task = []
select_source = []

keywords = [
    "MAP_REPLICATE_TASK for ",
    "SELECT_SHARDING_FUNCTOR ",
    "SLICE_TASK for ",
    "MAP_TASK for ",
    "SELECT_TASK_SOURCES for ",
]

placement = {} # taskname --> (proc, mem)

def read_from_file(filename):
    with open(filename, "r") as fin:
        return fin.readlines()

def trim(lines):
    # trim the leading `[0 - 20006fecf8b0]    0.451730 {2}{mapper}:`
    res = []
    for line in lines:
        if "{mapper}" not in line:
            # skip customized mapper's log
            continue
        # delete anything before }:
        trimmed = re.sub(r'.*}:', "", line).strip()
        res.append(trimmed)
    return res

def init(lines):
    # initialize charmap
    for line in lines:
        if "_PROC" not in line and "_MEM" not in line:
            continue
        # 1d00000000000010 (TOC_PROC) 
        chars, hardware = line.split(" ")[:2]
        hardware = hardware.replace("(", "").replace(")", "")
        # print(chars, hardware)
        charmap[chars] = hardware
        if "MAP_TASK" in line:
            break

def call_start(line):
    for kw in keywords:
        if kw in line:
            return True
    return False

def group_lines(lines):
    res = [] # list of groups of lines, each group represents one mapping call (keyword)
    current_group = []
    for line in lines:
        if call_start(line):
            if len(current_group) > 0:
                res.append(current_group)
            current_group = [line]
        else:
            if len(current_group) > 0:
                current_group.append(line)
    return res

def handle_map_task(groups):
    for g in groups:
        taskname = ""
        proc = ""
        mem = ""
        for line in g:
            line = line.replace("MAP_TASK for ", "")
            if "(index_point" in line:
                # MAP_TASK for CorrectGhostOperators(index_point=(2,0,0))<5536>
                taskname = line.split("(")[0]
            else:
                # MAP_TASK for task_6<296>
                taskname = line.split("<")[0]
            
    taskname = ""
    proc = ""
    mem = ""
    skip = False
    enter_critical = False
    for line in lines:
        if "MAP_REPLICATE_TASK" in line or "SELECT_TASK_SOURCES" in line:
            # "TARGET PROCS" also appears in map_replicate_task
            # "memory=..." also appears in select_task_sources
            skip = True
            taskname = ""
            proc = ""
            mem = ""
        if "MAP_TASK for" in line:
            if enter_critical:
                # potential conflict, skip this
                skip = True
                taskname = ""
                proc = ""
                mem = ""
            else:
                skip = False
                enter_critical = True
                # print("enter_critical = True", line)
                # MAP_TASK for CorrectGhostOperators(index_point=(2,0,0))<5536>
                line = line.replace("MAP_TASK for ", "")
                if "(index_point" in line:
                    taskname = line.split("(")[0]
                else:
                    taskname = line.split("<")[0]
        # TARGET PROCS: 1d0000000000000f
        if "TARGET PROCS:" in line and skip == False:
            proc_char = line.replace("TARGET PROCS: ", "")
            proc = charmap[proc_char]
            placement[taskname] = (proc, "UNKNOWN")
        # PhysicalInstance[4000000001000003](memory=1e00000000000004,domain=<125 ...
        # Instance[4000000000000005](region=(8,*,8),memory=1e00000000000000,domain=<0,
        if "Instance" in line and "memory=" in line and skip == False:
            mem_char = re.search(r"memory=(.*),domain", line).group(1)
            mem = charmap[mem_char]
            placement[taskname] = (proc, mem)
            enter_critical = False
        if "OUTPUT INSTANCES" in line:
            enter_critical = False
    # print(placement)

def infer_one_kind(proc_str, default_memory_lst):
    conversion = {"TOC_PROC": "GPU",
                  "OMP_PROC": "OMP",
                  "LOC_PROC": "CPU",
                  "IO_PROC" : "IO"}
    task_list = []
    region_list = []
    for task in placement.keys():
        proc, mem = placement[task]
        if proc == proc_str and mem in default_memory_lst:
            task_list.append(task)
        if proc == proc_str and mem not in default_memory_lst:
            region_list.append((task, conversion[proc], conversion[mem]))
    task_str = ",".join(task_list)
    if len(task_list) > 0:
        print(f"Task {task_str} {conversion[proc_str]}")
    for region in region_list:
        print(f"Region {region[0]} {region[1]} {region[2]}")

def infer():
    infer_one_kind("TOC_PROC", ["GPU_FB_MEM", "UNKNOWN"])
    infer_one_kind("OMP_PROC", ["SYSTEM_MEM", "UNKNOWN"])
    infer_one_kind("LOC_PROC", ["SYSTEM_MEM", "UNKNOWN"])
    infer_one_kind("IO_PROC", ["UNKNOWN"])

def split_groups(groups):
    for g in groups:
        if keywords[0] in g[0]:
            map_replicate.append(g)
        elif keywords[1] in g[0]:
            sharding.append(g)
        elif keywords[2] in g[0]:
            slicing.append(g)
        elif keywords[3] in g[0]:
            map_task.append(g)
        elif keywords[4] in g[0]:
            select_source.append(g)
        else:
            assert False, g[0]

if __name__ == "__main__":
    filename = sys.argv[1]
    lines = trim(read_from_file(filename)[:1000])
    init(lines)
    groups = group_lines(lines)
    split_groups(groups)
    print(map_task[:10])
    # map_task(groups)
    # infer()
