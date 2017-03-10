#!/bin/bash

protocol=$1

python IPParser1.py

input="txt/IPv$1.txt"
echo "Using IPv4:"
while IFS= read -r var
do 
  echo "Tracerouting $var"
  traceroute -$1 -q 1 -n $var | python IPParser2.py >> txt/traceroutedIPv$1.txt
done <"$input"

echo "graph routertopology {" > dot/routertopology-v$1.dot
cat txt/traceroutedIPv$1.txt | sort | uniq >> dot/routertopology-v$1.dot
echo "}" >> dot/routertopology-v$1.dot

dot -Tpdf dot/routertopology-v$1.dot -o pdf/routertopology-v$1.pdf