#!/bin/bash

gcc -std=c2x test.c -O0 -g3 -march=native -Warray-bounds  -Wpedantic -Wall -Wextra -Wconversion -lm -mavx2
# gcc -O0 test.c  -O3 -march=native -S -Warray-bounds -Wall -Wextra  -lm -mavx2