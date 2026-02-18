#!/bin/bash

echo "Компіляція"
gcc z4.c -o z4
gcc z5.c -o z5
gcc z6.c -o z6

echo -e "\nРозмір файлу -f"
dd if=/dev/urandom of=src_test.txt bs=1024 count=5 2>/dev/null
ulimit -f 1
./z5 src_test.txt dest_test.txt
echo "\nСкопійовано $(stat -c%s dest_test.txt 2>/dev/null || echo 0) байтів"

echo -e "\nРозмір стека -s"
ulimit -f unlimited
ulimit -s 64
./z6

echo -e "\nЧас процесора -t"
ulimit -s unlimited
ulimit -t 1
./z4 > "tickets.txt"
