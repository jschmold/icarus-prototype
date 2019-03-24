#! /usr/bin/bash
# Monsier son (mudmansteve) helped with this {Lightning McQueen}
# He helped check me reality on this and simplified the script
rm compile_compands.json
make clean
bear make
compdb -p . list >> compile_compands.json
