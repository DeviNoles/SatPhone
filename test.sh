#!/bin/bash

# File: test.sh
# Description: Does unit testing on satcom.

SRC="./src"     # Source code dir.
TEST="./test"   # Unit tests dir.


# Do Input Testing
for f in $TEST/1*.in; do
   f=${f%*.in}
   ./moure < ${f}.in > ${f}.tmp
   DIFF=$(diff ${f}.ans ${f}.tmp)
   if [ "$DIFF" != "" ]; then
      echo "${f} failed <---"
   else
      echo "${f} passed"
   fi
   rm ${f}.tmp
done

