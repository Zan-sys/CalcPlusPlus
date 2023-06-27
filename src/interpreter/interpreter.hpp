#ifndef INTERPRETER_HPP /* Begin INTERPRETER_HPP */
#define INTERPRETER_HPP
// ---------------------------------------------------------------------------
#include <limits>
#include <deque>
// ---------------------------------------------------------------------------
#include "action_tree.hpp"              // Модуль описвает узел дерева разбора
// ---------------------------------------------------------------------------
#define INTERPRETER_ERROR_VALUE             (std::numeric_limits<double>::quiet_NaN())
#define INTERPRETER_LOOP_LIMIT              (0xFFFF)
#define INTERPRETER_RECURSION_LIMIT         (0xFFFF)
#define INTERPRETER_GLOBAL_ARRAY_MAX_SIZE   (0xFFFF)
// ---------------------------------------------------------------------------
namespace CalcPlusPlus
{
// ---------------------------------------------------------------------------
class TInterpreter {
private:
    double err_value;                   // Значение по умолчанию, если возникает ошибка
    std::size_t loop_limit;             // Ограничение по количеству итераций в цикле
    std::shared_ptr<TActionNode> root;  // Корневой узел дерева разбора

    std::deque<double> global_array;    // Глобальный массив

    std::vector<std::pair<bool, std::shared_ptr<TActionNode>>> node_stack;  // Стек для прохода по дереву разбора
    std::vector<std::size_t> var_counter_stack;                             // Стек для хранения счётчика переменных
    std::vector<double> result_stack;                                       // Стек для хранения результатов
    std::deque<double> var_stack;                                           // Стек для хранения переменных

    bool FindErrorNodeInErrorHandle(std::shared_ptr<TActionNode> handle, std::shared_ptr<TActionNode> error_node);  // Поиск узла с ошибкой в обработчике ошибок
    bool IsErrorHandleInStack(std::shared_ptr<TActionNode> error_node);                                             // Проверка наличия обработчиков ошибок в стеке

    bool IsValid(double value);     // Проверка правильности расчётов

    double cotan(double value);     // Котангенс (аргумент вводится в радианах)
    double sec(double value);       // Секанс (аргумент вводится в радианах)
    double csc(double value);       // Косеканс (аргумент вводится в радианах)
    double acotan(double value);    // Арккотангенс
    double asec(double value);      // Арксеканс
    double acsc(double value);      // Арккосеканс
    double cotanh(double value);    // Гиперболический котангенс (аргумент вводится в радианах)
    double sech(double value);      // Гиперболический секанс (аргумент вводится в радианах)
    double csch(double value);      // Гиперболический косеканс (аргумент вводится в радианах)
    double acotanh(double value);   // Гиперболический арккотангенс
    double asech(double value);     // Гиперболический арккотангенс
    double acsch(double value);     // Гиперболический арккосеканс
    double int_f(double value);     // Выделяет целую часть числа
    double frac(double value);      // Выделяет дробную часть числа
    double fact(double value);      // Факториал числа

    double poly(double x, const std::vector<double>& coeff); // Расчёт полинома

    bool CheckGlobalArray();                                                                                    // Ограничение размера глобального массива
    bool SetIdentifierValue(std::deque<double>& stack, std::shared_ptr<TActionNode> id, double value);          // Запись в идентификатор данных
    bool GetIdentifierValue(const std::deque<double>& stack, std::shared_ptr<TActionNode> id, double& value);   // Чтение данных из идентификатора

public:
    //
    // Конструктор
    //
    TInterpreter();
    //
    // Установка математического выражения интерпретатору
    //
    bool SetExpression(const std::string& expression, const TIncludeList& include_list, TExternalIdList& external_identifiers, std::string& error);
    //
    // Выполнение математического выражения
    //
    bool Run(double& result);
    //
    // Указатель на дерево разбора
    //
    std::shared_ptr<TActionNode> GetParseTree();
    //
    // Копия глобального массива
    //
    void GetGlobalArray(std::vector<double>& _global_array);
};
// ---------------------------------------------------------------------------
}
// ---------------------------------------------------------------------------
#endif  /* End INTERPRETER_HPP */