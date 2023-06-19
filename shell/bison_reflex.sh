#!/bin/bash

#build re/flex
if [ ! -f "./lib/RE-flex/bin/reflex" ]
then
    echo BUILD RE/FLEX
     cd ./lib/RE-flex
     . ./clean.sh
     . ./build.sh
     cd ./../../
fi

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