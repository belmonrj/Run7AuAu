#!/bin/bash
g++ -o analyze hadrontree.cxx analyze.cxx -g -O0 -Wall -lstdc++ `root-config --libs` -I$ROOTSYS/include

#valgrind -v --leak-check=yes --track-origins=yes ./analyze files.list vgtest.root
valgrind -v --leak-check=yes  ./analyze test.list vgtest.root

