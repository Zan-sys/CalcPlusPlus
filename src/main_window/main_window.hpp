/*
 * ОПИСАНИЕ:
 * МОДУЛЬ ОПИСЫВАЕТ КЛАСС ГЛАВНОГО ОКНА ПРОГРАММЫ
 *
 * ЯЗЫК:
 * РАЗРАБОТКА НА ЯЗЫКЕ ПРОГРАММИРОВАНИЯ С++17
 *
 * РАЗРАБОТЧИК:
 * Зайцев А. Н. ЭИО-21 ведущий инженер-программист. LMZ inc
*/
// ---------------------------------------------------------------------------
#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP /* Begin MAIN_WINDOW_HPP */
// ---------------------------------------------------------------------------
#include <project-config.hpp>
// ---------------------------------------------------------------------------
#include <sciter-x.h>
#include <sciter-x-window.hpp>
// ---------------------------------------------------------------------------
#include "./../interpreter/interpreter.hpp" // Модуль описывает математический интерпретатор
// ---------------------------------------------------------------------------
//
// Класс главного окна программы
//
class TMainWindow : public sciter::window
{
private:
    CalcPlusPlus::TExternalIdList external_identifiers;         // Список внешних переменных
    std::unique_ptr<CalcPlusPlus::TInterpreter> interpreter;    // Математический интерпретатор

public:
    SOM_PASSPORT_BEGIN(TMainWindow)
    SOM_FUNCS
    (
        SOM_FUNC(InitInterpreter),
        SOM_FUNC(GetParseTreeTree),
        SOM_FUNC(GetGlobalArray),
        SOM_FUNC(GetExternalId),
        SOM_FUNC(SetExternalId),
        SOM_FUNC(Run)
    )
    SOM_PASSPORT_END

    sciter::string MakeSciterString(std::string str);                               // Формирование строки для Sciter
    std::string SciterStringToStd(const sciter::string& str);                       // Преобразование строки Sciter в стандартную
    sciter::value InitInterpreter(const sciter::string& math_code);                 // Инициализация интерпретатора
    sciter::value BuildParseTree(std::shared_ptr<CalcPlusPlus::TActionNode> node);  // Формирование дерева разбора
    sciter::value GetParseTreeTree();                                               // Метод возвращает объект с деревом разбора
    sciter::value GetGlobalArray();                                                 // Метод возвращает данные из глобального массива интерпретатора
    sciter::value GetExternalId();                                                  // Метод возвращает список внешних переменных
    void SetExternalId(const std::vector<sciter::value>& values);                   // Метод инициализирует список внешних переменных
    sciter::value Run();                                                            // Выполнение математического выражения

public:
    TMainWindow(); // Конструктор
};
// ---------------------------------------------------------------------------
#endif /* End MAIN_WINDOW_HPP */