@echo off
cd .\src\interpreter

echo BISON - START
..\..\lib\bison\win_bison.exe .\_parser_bison.y
echo BISON - FINISH

echo RE/FLEX - START
..\..\lib\RE-flex\bin\win64\reflex.exe .\_scaner_reflex.l
echo RE/FLEX - FINISH

cd ..\..\