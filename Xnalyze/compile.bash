#!/bin/bash
g++ -o analyze hadrontree.cxx analyze.cxx -Wall -lstdc++ `root-config --libs` -I/usr/local/include/root


