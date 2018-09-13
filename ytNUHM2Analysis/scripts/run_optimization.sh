#!/bin/bash
if [ -e opt.txt ]; then
    rm -rf opt.txt
fi
root -b -q ytOptimization_plots.C > opt.txt
