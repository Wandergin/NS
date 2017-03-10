import os, sys

with open("output.txt","r+") as f:
    content = f.read()
    f.seek(0,0)
    f.write(line.rstrip('\r\n') + '\n' + content)