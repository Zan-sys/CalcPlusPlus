#!/bin/bash
echo "-------------------------"
echo "BISON, RE/FLEX"
echo "-------------------------"
bash ./shell/bison_reflex.sh
echo "-------------------------"
echo "SCITER"
echo "-------------------------"
bash ./shell/pack-resources.sh
echo "-------------------------"
