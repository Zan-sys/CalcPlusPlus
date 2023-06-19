@echo off
echo SCRIPT -^> Delete .\src\gui_resources.cpp
del .\src\gui_resources.cpp
echo SCRIPT -^> Make .\src\gui_resources.cpp
.\lib\sciter-js-sdk\bin\windows\packfolder.exe .\ui .\src\gui_resources.cpp -v "gui_resources"
echo SCRIPT -^> Finish
echo SCRIPT -^> Copy x64 sciter dll
copy /Y .\lib\sciter-js-sdk\bin\windows\x64\sciter.dll .\bin\
echo SCRIPT -^> Copy finish