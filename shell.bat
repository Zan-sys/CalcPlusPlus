@echo off
echo -------------------------
echo BISON, RE/FLEX
echo -------------------------
call ./shell/bison_reflex.bat
echo -------------------------
echo SCITER
echo -------------------------
call ./shell/pack-resources.bat
echo -------------------------
