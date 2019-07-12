#!/bin/sh
python randomtest.py 1 10000 > randomtest

tput setaf 5; echo "\n\nrandom amount of integers between (0 10000) 100x"
i="0"
while [ $i -lt 100 ]
do
    python randomtest.py 1 10000 > randomtest
    tput setaf 3; echo "\nintegers:"
    cat randomtest | wc -l
    arg="`cat randomtest`"
    tput setaf 6; echo "instruct:"
    tput setaf 2;
    ./push_swap/push_swap $arg | ./checker/checker $arg
i=$[i+1]
done
tput setaf 2; echo "\n"