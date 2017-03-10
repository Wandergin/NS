import sys

iparray = []

for line in sys.stdin:
    line = line.split("  ")
    if line != "\n" and line[0][0] != "t" and line[1] != "*\n":
        if len(iparray) == 0:
            firstEntry = line[1]
            iparray = [""]
        else:
            secondEntry = line[1]
            lastElement = iparray[-1]
            iparray += ['"{0}" -- "{1}"'.format(firstEntry,secondEntry)]
            firstEntry = line[1]

for e in iparray[1:]:
    print e