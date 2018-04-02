#!/bin/sh
#help me, im desperate
g++ -Wall -pedantic -std=c++11 ../u1.cpp

for p in input*; do
NUM=`echo $p | sed 's/input//g'`
./a.out < $p > temp1
cat output$NUM > temp2
diff temp1 temp2
rm temp1 temp2
done
