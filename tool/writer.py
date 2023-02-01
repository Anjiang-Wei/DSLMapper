import sys
import re

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

if __name__ == "__main__":
    filename = sys.argv[1]
    lines = trim(read_from_file(filename))
