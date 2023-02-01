import sys
import re

# 1d00000000000008 -> LOC_PROC
# 1e00000000000000 -> SYSTEM_MEM
charmap = {}


def read_from_file(filename):
    with open(filename, "r") as fin:
        return fin.readlines()

def trim(lines):
    # trim the leading `[0 - 20006fecf8b0]    0.451730 {2}{mapper}:`
    res = []
    for line in lines:
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

def map_task(lines):
    res = {} # taskname --> (proc, mem)
    taskname = ""
    proc = ""
    mem = ""
    skip = False
    for line in lines:
        if "MAP_REPLICATE_TASK" in line or "SELECT_TASK_SOURCES" in line:
            # "TARGET PROCS" also appears in map_replicate_task
            # "memory=..." also appears in select_task_sources
            skip = True
        if "MAP_TASK for" in line:
            skip = False
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
        # PhysicalInstance[4000000001000003](memory=1e00000000000004,domain=<125 ...
        if "PhysicalInstance" and "memory=" in line and skip == False:
            mem_char = re.search(r"memory=(.*),domain", line).group(1)
            mem = charmap[mem_char]
            res[taskname] = (proc, mem)
    print(res)



if __name__ == "__main__":
    filename = sys.argv[1]
    lines = trim(read_from_file(filename))
    init(lines)
    map_task(lines)
    # print('\n'.join(lines[:20]))
