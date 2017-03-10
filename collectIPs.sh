#!/bin/bash

name=$1
echo "$1" >> txt/names.txt
./dnslookup $1 >> txt/IPs.txt
