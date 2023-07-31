#!/bin/sh

g++ -o main main.cc sum.cc -fprofile-arcs -ftest-coverage -g
./main
gcov main.cc sum.cc
