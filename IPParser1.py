unparsedIPs = []
with open("txt/IPs.txt", "r") as f:
    for line in f:
        unparsedIPs += [line]
        
IPv4s = []
IPv6s = []
for line in unparsedIPs:
    if len(line) > 10:
        if line[0:4] =="IPv4":
            IPv4s += [line[7:]]
        elif line[0:4] =="IPv6":
            IPv6s += [line[7:]]

with open("txt/IPv4.txt","w") as f:
    for IP in IPv4s:
        f.write(IP)

with open("txt/IPv6.txt","w") as f:
    for IP in IPv6s:
        f.write(IP)