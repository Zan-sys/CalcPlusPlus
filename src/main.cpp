
/*
 * ОПИСАНИЕ:
 * МОДУЛЬ ОПИСЫВАЕТ ТОЧКУ ВХОДА В ПРОГРАММУ ДЛЯ ГРАФИЧЕСКОГО РЕЖИМА РАБОТЫ
 *
 * ЯЗЫК:
 * РАЗРАБОТКА НА ЯЗЫКЕ ПРОГРАММИРОВАНИЯ >= С++17
 *
 * РАЗРАБОТЧИК:
 * Зайцев А. Н. ЭИО-21 ведущий инженер-программист. LMZ inc
*/
// ---------------------------------------------------------------------------
#include <project-config.hpp>
// ---------------------------------------------------------------------------
#include "./main_window/main_window.hpp" // Модуль описывает класс главного окна программы
// ---------------------------------------------------------------------------
//
// Ресурс содержит упакованный графический интерфейс программы
//
#include "./gui_resources.cpp"
// ---------------------------------------------------------------------------
//
// ТОЧКА ВХОДА В ПРОГРАММУ ПРИ СБОРКЕ В ГРАФИЧЕСКОМ РЕЖИМЕ С ГРАФИЧЕСКОЙ БИБЛИОТЕКОЙ SCITER
//
int uimain(std::function<int()> run)
{
    std::locale::global(std::locale(locale_name)); // Установка кодировки

    ::SciterSetOption(nullptr, SCITER_SET_DEBUG_MODE, true);
    ::SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES, ALLOW_FILE_IO | ALLOW_SOCKET_IO | ALLOW_EVAL | ALLOW_SYSINFO );

    sciter::archive::instance().open(aux::elements_of(gui_resources));

    sciter::om::hasset<TMainWindow> main_window = new TMainWindow();

    main_window->load(WSTR("this://app/main.htm"));

    main_window->expand();

    return run();
}
// ---------------------------------------------------------------------------
