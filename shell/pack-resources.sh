#!/bin/bash
# Генерация файла ./src/gui-resources.cpp из содержимого каталога ./ui/
# !!!Важно!!!При запуске скрипта текущим каталогом должен быть каталог с файлом скрипта
echo "SCRIPT -> Delete ./src/gui_resources.cpp"
rm -fv ./src/gui_resources.cpp
echo "SCRIPT -> Make ./src/gui_resources.cpp"
./lib/sciter-js-sdk/bin/linux/packfolder ./ui ./src/gui_resources.cpp -v "gui_resources"
echo "SCRIPT -> Finish"
echo "SCRIPT -> Copy x64 sciter dll"
cp -uv ./lib/sciter-js-sdk/bin/linux/x64/libsciter.so ./bin/
echo "SCRIPT -> Copy finish"