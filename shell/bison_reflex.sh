#!/bin/bash
cd ./src/interpreter

#bison
echo "BISON - START"
bison ./_parser_bison.y
echo "BISON - FINISH"

#re/flex
echo "RE/FLEX - START"
./../../lib/RE-flex/bin/reflex ./_scaner_reflex.l
echo "RE/FLEX - FINISH" 

cd ./../../