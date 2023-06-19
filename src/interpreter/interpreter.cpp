// ---------------------------------------------------------------------------
#include "interpreter.hpp"
// ---------------------------------------------------------------------------
#include <fw_base.hpp>
// ---------------------------------------------------------------------------
//
// STL
//
#include <cmath>
// ---------------------------------------------------------------------------
#include "scanner.hpp"  // Модуль описвает сканер
#include "parser.hpp"   // Модуль описывет парсер
// ---------------------------------------------------------------------------
using namespace std;
using namespace CalcPlusPlus;
using namespace Framework::StdExtension;
// ---------------------------------------------------------------------------
using TSEncoding = Framework::String::TEncoding<string>;
// ---------------------------------------------------------------------------
#define M_PI                            3.14159265358979323846 /* pi */
// ---------------------------------------------------------------------------
#define SET_ERROR_VALUE(VALUE)              (VALUE = INTERPRETER_ERROR_VALUE)
// ---------------------------------------------------------------------------
//
// Добавление данных в вектор
//
template<typename T> void PushBack(vector<T>& Container, T& value)
{
    Container.push_back(value);
}
// ---------------------------------------------------------------------------
//
// Удаление из контейнера несколько последних элементов
//
template<typename T> void EraseEnd(T& Container, size_t num)
{
    if ((num > 0) && (size(Container) >= num))
    {
        Container.erase(prev(end(Container), num), end(Container));
    }
}
// ---------------------------------------------------------------------------
//
// Предпоследние данные
//
template <typename Type> typename Type::value_type& PENULT(Type& Container)
{
    if (size(Container) >= 2)
    {
        return Container.at(size(Container) - 2);
    }
    else
    {
        return Container.back();
    }
}
// ---------------------------------------------------------------------------
//
// Конструктор
//
TInterpreter::TInterpreter() : err_value(INTERPRETER_ERROR_VALUE), loop_limit(INTERPRETER_LOOP_LIMIT), root(nullptr) {}
// ---------------------------------------------------------------------------
//
// Проверка правильности расчётов
//
bool TInterpreter::IsValid(double value)
{
    bool result(isnan(value) || isinf(value));
    return !result;
}
// ---------------------------------------------------------------------------
//
// Котангенс (аргумент вводится в радианах)
//
double TInterpreter::cotan(double value)
{
    double _cos(cos(value));
    double _sin(sin(value));
    return IsValid(_cos) && IsValid(_sin) && _sin != 0 ? _cos/_sin : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Секанс (аргумент вводится в радианах)
// 
double TInterpreter::sec(double value)
{
    double _cos(cos(value));
    return IsValid(_cos) && _cos != 0 ? 1 / _cos : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Косеканс (аргумент вводится в радианах)
//
double TInterpreter::csc(double value)
{
    double _sin(sin(value));
    return IsValid(_sin) && _sin != 0 ? 1 / _sin : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Арккотангенс
//
double TInterpreter::acotan(double value)
{
    double _atan(atan(value));
    return IsValid(_atan) ? (M_PI / 2) - _atan : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Арксеканс
//
double TInterpreter::asec(double value)
{
    return IsValid(value) && value != 0 ? acos(1/value) : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Арккосеканс
//
double TInterpreter::acsc(double value)
{
    return IsValid(value) && value != 0 ? asin(1/value) : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Гиперболический котангенс (аргумент вводится в радианах)
//
double TInterpreter::cotanh(double value)
{
    double _tanh(tanh(value));
    return IsValid(_tanh) && _tanh != 0 ? 1/_tanh : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Гиперболический секанс (аргумент вводится в радианах)
//
double TInterpreter::sech(double value)
{
    double _cosh(cosh(value));
    return IsValid(_cosh) && _cosh != 0 ? 1/_cosh : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Гиперболический косеканс (аргумент вводится в радианах)
//
double TInterpreter::csch(double value)
{
    double _sinh(sinh(value));
    return IsValid(_sinh) && _sinh != 0 ? 1/_sinh : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Гиперболический арккотангенс
//
double TInterpreter::acotanh(double value)
{
    return value > 1 ? log(sqrt(pow(value, 2) - 1) / (value - 1)) : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Гиперболический арккотангенс
//
double TInterpreter::asech(double value)
{
    return value > 0 && value <= 1 ? log((1 + sqrt(1 - pow(value, 2))) / value) : INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Гиперболический арккосеканс
//
double TInterpreter::acsch(double value)
{
    if (value != 0)
    {
        double _sgn(value < 0 ? -1 : 1);
        return log((1 + _sgn * sqrt(1 + pow(value, 2))) / value);
    }
    return INTERPRETER_ERROR_VALUE;
}
// ---------------------------------------------------------------------------
//
// Выделяет целую часть числа
//
double TInterpreter::int_f(double value)
{
    double result(0);
    modf(value, &result);
    return result;
}
// ---------------------------------------------------------------------------
//
// Выделяет дробную часть числа
//
double TInterpreter::frac(double value)
{
    double int_part(0);
    return modf(value, &int_part);
}
// ---------------------------------------------------------------------------
//
// Факториал числа
//
double TInterpreter::fact(double value)
{
    if(value < 0) return 0;                 // Если пользователь ввел отрицательное число возвращаем ноль
    if (value == 0) return 1;               // Если пользователь ввел ноль, возвращаем факториал от нуля - 1
    else return value * fact(value - 1);    // Делаем рекурсию
}
// ---------------------------------------------------------------------------
//
// Расчёт полинома
//
double TInterpreter::poly(double x, const std::vector<double>& coeff)
{
    if (size(coeff) == 0) return x;

    try
    {
        double subx(x);
        double result(coeff.at(0));

        for (size_t i = 1; i < size(coeff); i++)
        {
            if (i > 1) subx *= x;
            result = result + (coeff.at(i) * subx);
        }

        return isnormal(result) ? result : x;
    }
    catch(...)
    {
        return x;
    }
}
// ---------------------------------------------------------------------------
//
// Ограничение размера глобального массива
//
bool TInterpreter::CheckGlobalArray()
{
    if (size(global_array) > INTERPRETER_GLOBAL_ARRAY_MAX_SIZE)
    {
        global_array.resize(INTERPRETER_GLOBAL_ARRAY_MAX_SIZE);
        return false;
    }

    return true;
}
// ---------------------------------------------------------------------------
//
// Запись в идентификатор данных
//
bool TInterpreter::SetIdentifierValue(std::deque<double>& stack, std::shared_ptr<TActionNode> id, double value)
{
    if (id && (id->Type == TActionType::Identifier))
    {
        //
        // Идентификатор является внешней переменной
        //
        if (id->ExternalID)
        {
            *(id->ExternalID) = value;
        }
        else if ((id->Index >= 0) && size(stack) > static_cast<size_t>(id->Index)) // Идентификатор находится в стеке
        {
            stack.at(static_cast<size_t>(id->Index)) = value;
        }
        else // !!!ОШИБКА!!! Выход за пределы стека
        {
            return false;
        }

        return true;
    }
    return false;
}
// ---------------------------------------------------------------------------
//
// Чтение данных из идентификатора
//
bool TInterpreter::GetIdentifierValue(const std::deque<double>& stack, std::shared_ptr<TActionNode> id, double& value)
{
    if (id && (id->Type == TActionType::Identifier))
    {
        if (id->ExternalID) // Идентификатор является внешней переменной
        {
            value = *(id->ExternalID);
        }
        else if ((id->Index >= 0) && size(stack) > static_cast<size_t>(id->Index)) // Идентификатор находится в стеке
        {
            value = stack.at(static_cast<size_t>(id->Index));
        }
        else // !!!ОШИБКА!!! Выход за пределы стека
        {
            return false;
        }

        return true;
    }

    return false;
}
// ---------------------------------------------------------------------------
//
// Установка математического выражения интерпретатору
//
bool TInterpreter::SetExpression(const std::string& expression, const TIncludeList& include_list, TExternalIdList& external_identifiers, std::string& error)
{
    err_value       = INTERPRETER_ERROR_VALUE;
    loop_limit      = INTERPRETER_LOOP_LIMIT;
    root            = nullptr;

    global_array.clear();

    external_identifiers.clear();

    stringstream out_stream;

    auto _program(make_shared<TActionNode>(TActionType::Program));

    string utf8_expression(TSEncoding::ToUtf8(expression));

    /* include_list - используется в Сервере ИВК*/
    TScanner scanner(/*include_list, */ utf8_expression, out_stream);

    if (TParser parser(scanner, *_program, error); parser.parse() == 0)
    {
        root = TActionNode::SemanticCheck(_program, external_identifiers, error);
    }

    return root != nullptr;
}
// ---------------------------------------------------------------------------
//
// Выполнение математического выражения
//
bool TInterpreter::Run(double& result)
{
    if (root)
    {
        result = 0.0;
        //
        // Загружаем корневой узел дерева разбора
        //
        node_stack.push_back(pair(false, root));
        //
        // Выполнение математического выражения
        //
        while (!node_stack.empty())
        {
            //
            // Выход из цикла обработки, если обнаружена ошибка
            //
            if (!IsValid(result))
                break;
            //
            // Чтение узла из стека
            //
            auto [popup, node] = node_stack.back();
            //
            // Количество дочерних элементов узла
            //
            size_t size_nodes = size(node->Nodes);
            //
            // Количество элементов в стеке результатов
            //
            size_t size_result_stack = size(result_stack);
            //
            // Узел готов к удалению из стека требуется обработка
            //
            if (popup)
            {
                node_stack.pop_back();

                switch (node->Type)
                {
                    //
                    // Программа
                    //
                case TActionType::Program:
                    {
                        if (size_result_stack == 1)
                        {
                            result = BACK(result_stack);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Опции программы, Переменные, Блок Main
                    //
                case TActionType::Options:      // Опции программы
                case TActionType::Variables:    // Список переменных
                case TActionType::Main:         // Бок основных инструкций
                    break;
                    //
                    // Значение переменной или выражения в случае ошибки
                    //
                case TActionType::OptErrorValue:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            err_value = BACK(result_stack);
                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Максимальное количество итераций в цикле
                    //
                case TActionType::OptLoopLimit:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            loop_limit = static_cast<size_t>(BACK(result_stack));
                            if (loop_limit == 0) loop_limit = INTERPRETER_LOOP_LIMIT;
                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Объявление переменной
                    //
                case TActionType::Var:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            auto id(FRONT(node->Nodes)); // Идентификатор переменной
                            auto id_math(size_nodes > 1 ? BACK(node->Nodes) : nullptr);

                            if (double value(0.0); id_math)
                            {
                                value = BACK(result_stack);
                                //
                                // Сохраняем результат в идентификатор
                                //
                                if (!SetIdentifierValue(var_stack, id, value))
                                {
                                    SET_ERROR_VALUE(result);
                                }
                            }

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // =
                    //
                case TActionType::Assignment:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            auto id(FRONT(node->Nodes));
                            double value(BACK(result_stack));
                            //
                            // Сохраняем результат в идентификатор
                            //
                            if (!SetIdentifierValue(var_stack, id, value))
                            {
                                SET_ERROR_VALUE(result);
                            }

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // ++ --
                    //
                case TActionType::PlusPlus:
                case TActionType::MinusMinus:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            auto id(FRONT(node->Nodes));
                            double value(BACK(result_stack));
                            EraseEnd(result_stack, size_nodes);

                            if (node->Is(TActionType::PlusPlus))
                            {
                                value++;
                            }
                            else
                            {
                                value--;
                            }
                            //
                            // Сохраняем результат в идентификатор
                            //
                            if (!SetIdentifierValue(var_stack, id, value))
                            {
                                SET_ERROR_VALUE(result);
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // += -= *= /=
                    //
                case TActionType::PlusAssignment:       // +=
                case TActionType::MinusAssignment:      // -=
                case TActionType::MultAssignment:       // *=
                case TActionType::DivisionAssignment:   // /=
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            auto id(FRONT(node->Nodes));

                            double rvalue(0.0);
                            double value1(PENULT(result_stack));
                            double value2(BACK(result_stack));
                            EraseEnd(result_stack, size_nodes);

                            switch (node->Type)
                            {
                                case TActionType::PlusAssignment:       rvalue = value1 + value2; break; // +=
                                case TActionType::MinusAssignment:      rvalue = value1 - value2; break; // -=
                                case TActionType::MultAssignment:       rvalue = value1 * value2; break; // *=
                                case TActionType::DivisionAssignment:   rvalue = value2 == 0.0 ? INTERPRETER_ERROR_VALUE : value1 / value2; break; // /=
                                default: SET_ERROR_VALUE(rvalue); break;
                            }

                            if (!(IsValid(rvalue) && SetIdentifierValue(var_stack, id, rvalue)))
                            {
                                SET_ERROR_VALUE(result);
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // 3.14
                    //
                case TActionType::Pi:
                    {
                        result_stack.push_back(M_PI);
                    }
                    break;
                    //
                    // Функция возвращает ошибку
                    //
                case TActionType::ErrorValue:
                    {
                        PushBack(result_stack, err_value);
                    }
                    break;
                    //
                    // Переменная содержит значение ошибки
                    //
                case TActionType::IsErrorValue:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double value(BACK(result_stack));
                            EraseEnd(result_stack, size_nodes);

                            if (IsValid(value))
                            {
                                value = AreSame<double>(value, err_value);
                            }
                            else
                            {
                                value = true;
                            }

                            PushBack(result_stack, value);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Проверка на наличие ошибки в математическом выражении
                    //
                case TActionType::IfErrValueDef:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double value1(PENULT(result_stack));
                            double value2(BACK(result_stack));
                            EraseEnd(result_stack, size_nodes);

                            if (IsValid(value1) && !AreSame<double>(value1, err_value))
                            {
                                PushBack(result_stack, value1);
                            }
                            else
                            {
                                PushBack(result_stack, value2);
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Встроенные формулы
                    //
                case TActionType::Ln:       // Натуральный логарифм
                case TActionType::Lg:       // Десятичный логарифм
                case TActionType::Sin:      // Синус (аргумент вводится в радианах)
                case TActionType::Cos:      // Косинус (аргумент вводится в радианах)
                case TActionType::Tan:      // Тангенс (аргумент вводится в радианах)
                case TActionType::CoTan:    // Котангенс (аргумент вводится в радианах)
                case TActionType::Sec:      // Секанс (аргумент вводится в радианах)
                case TActionType::Csc:      // Косеканс (аргумент вводится в радианах)
                case TActionType::ASin:     // Арксинус
                case TActionType::ACos:     // Арккосинус
                case TActionType::ATan:     // Арктангенс (аргумент вводится в радианах)
                case TActionType::ACoTan:   // Арккотангенс
                case TActionType::ASec:     // Арксеканс
                case TActionType::ACsc:     // Арккосеканс
                case TActionType::SinH:     // Гиперболический синус
                case TActionType::CosH:     // Гиперболический косинус
                case TActionType::TanH:     // Гиперболический тангенс
                case TActionType::CoTanH:   // Гиперболический котангенс (аргумент вводится в радианах)
                case TActionType::SecH:     // Гиперболический секанс (аргумент вводится в радианах)
                case TActionType::CscH:     // Гиперболический косеканс (аргумент вводится в радианах)
                case TActionType::ASinH:    // Гиперболический арксинус
                case TActionType::ACosH:    // Гиперболический арккосинус
                case TActionType::ATanH:    // Гиперболический арктангенс
                case TActionType::ACoTanH:  // Гиперболический арккотангенс
                case TActionType::ASecH:    // Гиперболический арксеканс
                case TActionType::ACscH:    // Гиперболический арккосеканс
                case TActionType::Abs:      // Абсолютное значение
                case TActionType::Sqrt:     // Квадратный корень числа
                case TActionType::Int:      // Выделяет целую часть числа
                case TActionType::Frac:     // Выделяет дробную часть числа
                case TActionType::Sqr:      // Возводит аргумент в квадрат
                case TActionType::Cube:     // Возводит аргумент в кубическую степень
                case TActionType::Round:    // Округляет число до ближайшего целого
                case TActionType::Fact:     // Факториал
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);
                            double value(BACK(result_stack));
                            EraseEnd(result_stack, size_nodes);

                            switch (node->Type)
                            {
                                case TActionType::Ln:       rvalue = log(value);        break; // Натуральный логарифм
                                case TActionType::Lg:       rvalue = log10(value);      break; // Десятичный логарифм
                                case TActionType::Sin:      rvalue = sin(value);        break; // Синус (аргумент вводится в радианах)
                                case TActionType::Cos:      rvalue = cos(value);        break; // Косинус (аргумент вводится в радианах)
                                case TActionType::Tan:      rvalue = tan(value);        break; // Тангенс (аргумент вводится в радианах)
                                case TActionType::CoTan:    rvalue = cotan(value);      break; // Котангенс (аргумент вводится в радианах)
                                case TActionType::Sec:      rvalue = sec(value);        break; // Секанс (аргумент вводится в радианах)
                                case TActionType::Csc:      rvalue = csc(value);        break; // Косеканс (аргумент вводится в радианах)
                                case TActionType::ASin:     rvalue = asin(value);       break; // Арксинус
                                case TActionType::ACos:     rvalue = acos(value);       break; // Арккосинус
                                case TActionType::ATan:     rvalue = atan(value);       break; // Арктангенс (аргумент вводится в радианах)
                                case TActionType::ACoTan:   rvalue = acotan(value);     break; // Арккотангенс
                                case TActionType::ASec:     rvalue = asec(value);       break; // Арксеканс
                                case TActionType::ACsc:     rvalue = acsc(value);       break; // Арккосеканс
                                case TActionType::SinH:     rvalue = sinh(value);       break; // Гиперболический синус
                                case TActionType::CosH:     rvalue = cosh(value);       break; // Гиперболический косинус
                                case TActionType::TanH:     rvalue = tanh(value);       break; // Гиперболический тангенс
                                case TActionType::CoTanH:   rvalue = cotanh(value);     break; // Гиперболический котангенс (аргумент вводится в радианах)
                                case TActionType::SecH:     rvalue = sech(value);       break; // Гиперболический секанс (аргумент вводится в радианах)
                                case TActionType::CscH:     rvalue = csch(value);       break; // Гиперболический косеканс (аргумент вводится в радианах)
                                case TActionType::ASinH:    rvalue = asinh(value);      break; // Гиперболический арксинус
                                case TActionType::ACosH:    rvalue = acosh(value);      break; // Гиперболический арккосинус
                                case TActionType::ATanH:    rvalue = atanh(value);      break; // Гиперболический арктангенс
                                case TActionType::ACoTanH:  rvalue = acotanh(value);    break; // Гиперболический арккотангенс
                                case TActionType::ASecH:    rvalue = asech(value);      break; // Гиперболический арксеканс
                                case TActionType::ACscH:    rvalue = acsch(value);      break; // Гиперболический арккосеканс
                                case TActionType::Abs:      rvalue = abs(value);        break; // Абсолютное значение
                                case TActionType::Sqrt:     rvalue = sqrt(value);       break; // Квадратный корень числа
                                case TActionType::Int:      rvalue = int_f(value);      break; // Выделяет целую часть числа
                                case TActionType::Frac:     rvalue = frac(value);       break; // Выделяет дробную часть числа
                                case TActionType::Sqr:      rvalue = pow(value, 2);     break; // Возводит аргумент в квадрат
                                case TActionType::Cube:     rvalue = pow(value, 3);     break; // Возводит аргумент в кубическую степень
                                case TActionType::Round:    rvalue = round(value);      break; // Округляет число до ближайшего целого
                                case TActionType::Fact:     rvalue = fact(value);       break; // Факториал
                                default:                    SET_ERROR_VALUE(rvalue);    break;
                            }

                            PushBack(result_stack, rvalue);

                            if (!IsValid(rvalue))
                            {
                                SET_ERROR_VALUE(result);
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Встроенные формулы
                    //
                case TActionType::Pow: // Возведение числа в степень
                case TActionType::Inc: // Увеличение числа
                case TActionType::Dec: // Уменьшение числа
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);
                            double value1(PENULT(result_stack));
                            double value2(BACK(result_stack));
                            EraseEnd(result_stack, size_nodes);

                            switch (node->Type)
                            {
                                case TActionType::Pow:  rvalue = pow(value1, value2);   break; // Возведение числа в степень
                                case TActionType::Inc:  rvalue = value1 + value2;       break; // Увеличение числа
                                case TActionType::Dec:  rvalue = value1 - value2;       break; // Уменьшение числа
                                default:                SET_ERROR_VALUE(rvalue);        break; // Неизвестная операция
                            }

                            PushBack(result_stack, rvalue);

                            if (!IsValid(rvalue))
                            {
                                SET_ERROR_VALUE(result);
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Вычисляет сумму аргументов
                    //
                case TActionType::Sum:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);
                            for (auto it(prev(end(result_stack), size_nodes)); it != end(result_stack); it++)
                            {
                                rvalue += *it;
                            }
                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Определяет максимальное/минимальное значение из аргументов
                    //
                case TActionType::Max:
                case TActionType::Min:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);

                            if (node->Is(TActionType::Max))
                            {
                                rvalue = *max_element(prev(end(result_stack), size_nodes), end(result_stack));
                            }
                            else
                            {
                                rvalue = *min_element(prev(end(result_stack), size_nodes), end(result_stack));
                            }

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Осредненное значение
                    //
                case TActionType::Avg:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);

                            for (auto it(prev(end(result_stack), size_nodes)); it != end(result_stack); it++)
                            {
                                rvalue += *it;
                            }

                            rvalue /= size_nodes;

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Вычисляет произведение аргументов
                    //
                case TActionType::Prod:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(1);

                            for (auto it(prev(end(result_stack), size_nodes)); it != end(result_stack); it++)
                            {
                                rvalue *= *it;
                            }

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Расчёт полинома
                    //
                case TActionType::Poly:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            vector<double> coeff;
                            copy(prev(end(result_stack), size_nodes), end(result_stack), back_inserter(coeff));

                            double x(FRONT(coeff));
                            coeff.erase(begin(coeff));
                            double rvalue = poly(x, coeff);

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Инициализация массива
                    //
                case TActionType::Void_ArrayInit:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            global_array.clear();

                            copy(prev(end(result_stack), size_nodes), end(result_stack), back_inserter(global_array));

                            EraseEnd(result_stack, size_nodes);

                            if (!CheckGlobalArray()) SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Инициализация глобального массива если он пустой
                    //
                case TActionType::Void_ArrayInitIfEmpty:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            if (global_array.empty())
                            {
                                copy(prev(end(result_stack), size_nodes), end(result_stack), back_inserter(global_array));
                            }

                            EraseEnd(result_stack, size_nodes);

                            if (!CheckGlobalArray()) SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Количество элементов в глобальном массиве
                    //
                case TActionType::ArraySize:
                    {
                        result_stack.push_back(static_cast<double>(size(global_array)));
                    }
                    break;
                    //
                    // Удаление всех элементов из массива
                    //
                case TActionType::Void_ArrayClear:
                    {
                        global_array.clear();
                    }
                    break;
                    //
                    // Добавление элемента в конец массива
                    //
                case TActionType::Void_ArrayPushBack:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            copy(prev(end(result_stack), size_nodes), end(result_stack), back_inserter(global_array));

                            EraseEnd(result_stack, size_nodes);

                            if (!CheckGlobalArray()) SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Добавление элемента в начало массива
                    //
                case TActionType::Void_ArrayPushFront:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            reverse_copy(prev(end(result_stack), size_nodes), end(result_stack), front_inserter(global_array));

                            EraseEnd(result_stack, size_nodes);

                            if (!CheckGlobalArray()) SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Удаление элемента с конца массива
                    //
                case TActionType::Void_ArrayPopBack:
                    {
                        if (!global_array.empty())
                        {
                            global_array.pop_back();
                        }
                    }
                    break;
                    //
                    // Удаление элемента с начала массива
                    //
                case TActionType::Void_ArrayPopFront:
                    {
                        if (!global_array.empty())
                        {
                            global_array.pop_front();
                        }
                    }
                    break;
                    //
                    // Запись в массив данных по индексу
                    //
                case TActionType::Void_ArrayAt:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            size_t index(static_cast<size_t>(PENULT(result_stack)));
                            double value(BACK(result_stack));

                            if (index < size(global_array))
                            {
                                global_array.at(index) = value;
                            }
                            else SET_ERROR_VALUE(result);

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Чтение из массива данных по индексу
                    //
                case TActionType::ArrayAt:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            size_t index(static_cast<size_t>(BACK(result_stack)));

                            EraseEnd(result_stack, size_nodes);

                            if (index < size(global_array))
                            {
                                PushBack(result_stack, global_array.at(index));
                            }
                            else
                            {
                                result_stack.push_back(INTERPRETER_ERROR_VALUE);
                                SET_ERROR_VALUE(result);
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Чтение первого элемента массива
                    //
                case TActionType::ArrayFront:
                    {
                        if (!global_array.empty())
                        {
                            PushBack(result_stack, global_array.front());
                        }
                        else
                        {
                            result_stack.push_back(INTERPRETER_ERROR_VALUE);
                            SET_ERROR_VALUE(result);
                        }
                    }
                    break;
                    //
                    // Чтение последнего элемента массива
                    //
                case TActionType::ArrayBack:
                    {
                        if (!global_array.empty())
                        {
                            PushBack(result_stack, global_array.back());
                        }
                        else
                        {
                            result_stack.push_back(INTERPRETER_ERROR_VALUE);
                            SET_ERROR_VALUE(result);
                        }
                    }
                    break;
                    //
                    // Добавление новых элементов в массив перед другим элементом
                    //
                case TActionType::Void_ArrayInsert:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            auto it(prev(end(result_stack), size_nodes));

                            size_t index(static_cast<size_t>(*it));

                            it++;

                            if (index < size(global_array))
                            {
                                global_array.insert(next(begin(global_array), index), it, end(result_stack));
                            }
                            else
                            {
                                SET_ERROR_VALUE(result);
                            }

                            EraseEnd(result_stack, size_nodes);

                            if (!CheckGlobalArray()) SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Удаляет элемент из массива с определённым индексом
                    //
                case TActionType::Void_ArrayErase:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            if (size_nodes == 2) // Удаление диапазона элементов
                            {
                                size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                {
                                    global_array.erase(next(begin(global_array), indexB), next(begin(global_array), indexE + 1));
                                }
                                else SET_ERROR_VALUE(result);
                            }
                            else if (size_nodes == 1) // Удаление одного элемента
                            {
                                size_t index(static_cast<size_t>(BACK(result_stack)));

                                if (index < size(global_array))
                                {
                                    global_array.erase(next(begin(global_array), index));
                                }
                                else SET_ERROR_VALUE(result);
                            }
                            else SET_ERROR_VALUE(result);

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Удаляет все элементы с определённым значением
                    //
                case TActionType::Void_ArrayEraseValue:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            for (auto it(prev(end(result_stack), size_nodes)); it != end(result_stack); it++)
                            {
                                global_array.erase(remove(begin(global_array), end(global_array), *it), end(global_array));
                            }

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Изменение размера массива
                    //
                case TActionType::Void_ArrayResize:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            size_t new_size(0);
                            double value(0.0);

                            if (size_nodes == 2) // Изменение размера массива и инициализация
                            {
                                new_size = static_cast<size_t>(PENULT(result_stack));
                                value = BACK(result_stack);
                            }
                            else if (size_nodes == 1) // Изменение размера без инициализации
                            {
                                new_size = static_cast<size_t>(BACK(result_stack));
                            }
                            else SET_ERROR_VALUE(result);

                            if (new_size <= INTERPRETER_GLOBAL_ARRAY_MAX_SIZE)
                            {
                                global_array.resize(new_size, value);
                            }
                            else SET_ERROR_VALUE(result);

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Сортировка массива
                    //
                case TActionType::Void_ArraySort:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            if (size_nodes == 2) // Сортировка по диапазону индексов
                            {
                                size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                {
                                    sort(next(begin(global_array), indexB), next(begin(global_array), indexE + 1));
                                }
                                else SET_ERROR_VALUE(result);
                            }
                            else // Сортировка по всему массиву
                            {
                                sort(begin(global_array), end(global_array));
                            }

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Переворачивает данные массива
                    //
                case TActionType::Void_ArrayReverse:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            if (size_nodes == 2) // Переворот по диапазону
                            {
                                size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                {
                                    reverse(next(begin(global_array), indexB), next(begin(global_array), indexE + 1));
                                }
                                else SET_ERROR_VALUE(result);
                            }
                            else // Переворот всего массива
                            {
                                reverse(begin(global_array), end(global_array));
                            }

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Сортирует весь массив и удаляет все повторяющиеся значения
                    //
                case TActionType::Void_ArrayUnique:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            if (!global_array.empty())
                            {
                                sort(begin(global_array), end(global_array));
                                global_array.erase(unique(begin(global_array), end(global_array)), end(global_array));
                            }

                            EraseEnd(result_stack, size_nodes);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Произведение всех элементов массива
                    //
                case TActionType::ArrayProd:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(1.0);

                            if (!global_array.empty())
                            {
                                //
                                // Вычисление диапазона
                                //
                                auto it_begin(begin(global_array));
                                auto it_end(end(global_array));

                                if (size_nodes == 2)
                                {
                                    size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                    size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                    if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                    {
                                        it_begin = next(begin(global_array), indexB);
                                        it_end = next(begin(global_array), indexE + 1);
                                    }
                                    else SET_ERROR_VALUE(result);
                                }
                                //
                                // Расчёт
                                //
                                if (IsValid(result))
                                {
                                    for (auto it(it_begin); it != it_end; it++)
                                    {
                                        rvalue *= *it;
                                    }
                                }
                            }
                            else SET_ERROR_VALUE(result);

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Среднее значение всех элементов массива
                    //
                case TActionType::ArrayAvg:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);

                            if (!global_array.empty())
                            {
                                //
                                // Вычисление диапазона
                                //
                                auto it_begin(begin(global_array));
                                auto it_end(end(global_array));

                                if (size_nodes == 2)
                                {
                                    size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                    size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                    if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                    {
                                        it_begin = next(begin(global_array), indexB);
                                        it_end = next(begin(global_array), indexE + 1);
                                    }
                                    else SET_ERROR_VALUE(result);
                                }
                                //
                                // Расчёт
                                //
                                if (IsValid(result))
                                {
                                    for (auto it(it_begin); it != it_end; it++)
                                    {
                                        rvalue += *it;
                                    }
                                    rvalue /= distance(it_begin, it_end);
                                }
                            }
                            else SET_ERROR_VALUE(result);

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Минимальное/Максимальное значение из всех элементов массива
                    //
                case TActionType::ArrayMin:
                case TActionType::ArrayMax:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);

                            if (!global_array.empty())
                            {
                                //
                                // Вычисление диапазона
                                //
                                auto it_begin(begin(global_array));
                                auto it_end(end(global_array));

                                if (size_nodes == 2)
                                {
                                    size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                    size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                    if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                    {
                                        it_begin = next(begin(global_array), indexB);
                                        it_end = next(begin(global_array), indexE + 1);
                                    }
                                    else SET_ERROR_VALUE(result);
                                }
                                //
                                // Расчёт
                                //
                                if (IsValid(result))
                                {
                                    if (node->Is(TActionType::ArrayMin))
                                    {
                                        rvalue = *min_element(it_begin, it_end);
                                    }
                                    else
                                    {
                                        rvalue = *max_element(it_begin, it_end);
                                    }
                                }
                            }
                            else SET_ERROR_VALUE(result);

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Сумма всех элементов массива
                    //
                case TActionType::ArraySum:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);

                            if (!global_array.empty())
                            {
                                //
                                // Вычисление диапазона
                                //
                                auto it_begin(begin(global_array));
                                auto it_end(end(global_array));

                                if (size_nodes == 2)
                                {
                                    size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                    size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                    if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                    {
                                        it_begin = next(begin(global_array), indexB);
                                        it_end = next(begin(global_array), indexE + 1);
                                    }
                                    else SET_ERROR_VALUE(result);
                                }
                                //
                                // Расчёт
                                //
                                if (IsValid(result))
                                {
                                    for (auto it(it_begin); it != it_end; it++)
                                    {
                                        rvalue += *it;
                                    }
                                }
                            }
                            else SET_ERROR_VALUE(result);

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Пересчёт с учётом коэффициентов полинома
                    //
                case TActionType::ArrayPoly:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);
                            double x(0.0);
                            vector<double> coeff;

                            if (size_nodes == 3)
                            {
                                x = result_stack.at(size_result_stack - size_nodes);
                                size_t indexB(static_cast<size_t>(PENULT(result_stack)));
                                size_t indexE(static_cast<size_t>(BACK(result_stack)));

                                if ((indexB < size(global_array)) && (indexE < size(global_array)) && (indexB < indexE))
                                {
                                    copy(next(begin(global_array), indexB), next(begin(global_array), indexE + 1), back_inserter(coeff));
                                }
                                else SET_ERROR_VALUE(result);
                            }
                            else
                            {
                                x = BACK(result_stack);
                                copy(begin(global_array), end(global_array), back_inserter(coeff));
                            }

                            if (IsValid(result))
                            {
                                rvalue = poly(x, coeff);
                            }

                            EraseEnd(result_stack, size_nodes);
                            PushBack(result_stack, rvalue);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Оператор ветвления
                    //
                case TActionType::If:
                    {
                        if (size_result_stack >= 1)
                        {
                            double value(BACK(result_stack));
                            EraseEnd(result_stack, 1);

                            shared_ptr<TActionNode> true_block(node->Nodes.at(1));
                            shared_ptr<TActionNode> another_block(size_nodes == 3 ? BACK(node->Nodes) : nullptr);

                            if (value)
                            {
                                node_stack.push_back(pair(true_block->Nodes.empty(), true_block));
                            }
                            else if (another_block)
                            {
                                node_stack.push_back(pair(another_block->Nodes.empty(), another_block));
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // True блок, False блок - не возвращают результат, так как блок IF возвращает результат
                    //
                case TActionType::TrueBlock:
                case TActionType::FalseBlock:
                    break;
                    //
                    // Цикл while, do while, For
                    //
                case TActionType::While:
                case TActionType::DoWhile:
                case TActionType::For:
                    {
                        if (size_result_stack >= 1)
                        {
                            double value(BACK(result_stack));
                            EraseEnd(result_stack, 1);
                            //
                            // Первая итерация цикла
                            //
                            if (node->Index < 0)
                            {
                                node->Index = 0;
                            }
                            //
                            // Проверка на ограничение по количеству итераций
                            //
                            if (static_cast<size_t>(node->Index) < loop_limit)
                            {
                                if (value)
                                {
                                    node->Index++;

                                    node_stack.push_back(pair(false, node));

                                    if (node->Is(TActionType::While))
                                    {
                                        shared_ptr<TActionNode> block_code(BACK(node->Nodes));
                                        node_stack.push_back(pair(block_code->Nodes.empty(), block_code));
                                    }
                                    else if (node->Is(TActionType::For))
                                    {
                                        shared_ptr<TActionNode> block_code(PENULT(node->Nodes));
                                        node_stack.push_back(pair(false, BACK(node->Nodes)));
                                        node_stack.push_back(pair(block_code->Nodes.empty(), block_code));
                                    }
                                }
                                else // Последня итерация цикла
                                {
                                    node->Index = -1;
                                }
                            }
                            else SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                        //
                        // Сброс счётчика при ошибке
                        //
                        if (!IsValid(result))
                        {
                            node->Index = -1;
                        }
                    }
                    break;
                    //
                    // Выход из цикла
                    //
                case TActionType::Break:
                    {
                        shared_ptr<TActionNode> break_node;
                        do
                        {
                            break_node = BACK(node_stack).second;
                            node_stack.pop_back();

                        } while(!break_node->Is(TActionType::While) && !break_node->Is(TActionType::DoWhile) && !break_node->Is(TActionType::For));
                    }
                    break;
                    //
                    // Код цикла
                    //
                case TActionType::BlockCode:
                    break;
                    //
                    // Вызов функции
                    //
                case TActionType::InvokeFunction:
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            if (node->Invoke->Index < INTERPRETER_RECURSION_LIMIT)
                            {
                                var_counter_stack.push_back(size_nodes);

                                copy(prev(end(result_stack), size_nodes), end(result_stack), front_inserter(var_stack));

                                EraseEnd(result_stack, size_nodes);

                                node->Invoke->Index++;

                                node_stack.push_back(pair(false, node->Invoke));
                            }
                            else
                            {
                                node->Invoke->Index = 0;
                                SET_ERROR_VALUE(result);
                            }
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Завершение обработки функции
                    //
                case TActionType::Function:
                    {
                        if (size_result_stack >= 1)
                        {
                            size_t _var_counter(BACK(var_counter_stack));
                            var_counter_stack.pop_back();

                            node->Index--;

                            if (size(var_stack) >= _var_counter)
                            {
                                var_stack.erase(begin(var_stack), next(begin(var_stack), _var_counter));
                            }
                            else SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Число - константа
                    //
                case TActionType::Number:
                    {
                        PushBack(result_stack, node->Number);
                    }
                    break;
                    //
                    // true
                    //
                case TActionType::True:
                    {
                        result_stack.push_back(true);
                    }
                    break;
                    //
                    // false
                    //
                case TActionType::False:
                    {
                        result_stack.push_back(false);
                    }
                    break;
                    //
                    // Identifier
                    //
                case TActionType::Identifier:
                    {
                        if (double value(0.0); GetIdentifierValue(var_stack, node, value))
                        {
                            PushBack(result_stack, value);
                        }
                        else
                        {
                            SET_ERROR_VALUE(result);
                            result_stack.push_back(INTERPRETER_ERROR_VALUE);
                        }
                    }
                    break;
                    //
                    // + - * / > < == != <= >= && ||
                    //
                case TActionType::Plus: // +
                case TActionType::Minus: // -
                case TActionType::Multiplication: // *
                case TActionType::Division: // /
                case TActionType::Bigger: // >
                case TActionType::Smaller: // <
                case TActionType::EqualEqual: // ==
                case TActionType::NotEqual: // !=
                case TActionType::LessOrEqual: // <=
                case TActionType::GreatOrEqual: // >=
                case TActionType::And: // &&
                case TActionType::Or: // ||
                    {
                        if (size_result_stack >= size_nodes)
                        {
                            double rvalue(0.0);
                            double value1(PENULT(result_stack));
                            double value2(BACK(result_stack));
                            EraseEnd(result_stack, size_nodes);

                            switch (node->Type)
                            {
                                case TActionType::Plus:             rvalue = value1 + value2; break; // +
                                case TActionType::Minus:            rvalue = value1 - value2; break; // -
                                case TActionType::Multiplication:   rvalue = value1 * value2; break; // *
                                case TActionType::Division:         rvalue = value2 == 0.0 ? INTERPRETER_ERROR_VALUE : value1 / value2; break; // /
                                case TActionType::Bigger:           rvalue = value1 > value2; break; // >
                                case TActionType::Smaller:          rvalue = value1 < value2; break; // <
                                case TActionType::EqualEqual:       rvalue = AreSame<double>(value1, value2); break; // ==
                                case TActionType::NotEqual:         rvalue = value1 != value2; break; // !=
                                case TActionType::LessOrEqual:      rvalue = value1 <= value2; break;// <=
                                case TActionType::GreatOrEqual:     rvalue = value1 >= value2; break;// >=
                                case TActionType::And:              rvalue = value1 && value2; break; // &&
                                case TActionType::Or:               rvalue = value1 || value2; break; // ||
                                default: SET_ERROR_VALUE(rvalue); break;
                            }

                            PushBack(result_stack, rvalue);

                            if (!IsValid(rvalue)) SET_ERROR_VALUE(result);
                        }
                        else SET_ERROR_VALUE(result);
                    }
                    break;
                    //
                    // Узел заглушка
                    //
                case TActionType::Empty:
                    break;
                    //
                    // Ошибка выполнения программы
                    //
                default: SET_ERROR_VALUE(result); break;
                }
            }
            else // Предварительная обработка некоторых узлов и добавление дочерних элементов в стек
            {
                BACK(node_stack).first = true;
                //
                // Добавление дочерних элементов в стек  и первичная обработка узлов
                //
                switch (node->Type)
                {
                    //
                    // Инициализация счётчика переменных
                    //
                case TActionType::Program:
                    {
                        var_counter_stack.push_back(0);
                        //
                        // Добавляем дочерние аргументы, пропускаем узел Functions
                        //
                        for (auto it(rbegin(node->Nodes)); it != rend(node->Nodes); it++)
                        {
                            if (!(*it)->Is(TActionType::Functions))
                            {
                                node_stack.push_back(pair((*it)->Nodes.empty(), *it));
                            }
                        }
                    }
                    break;
                    //
                    // Добавление переменных в стек
                    //
                case TActionType::Variables:
                    {
                        BACK(var_counter_stack) += size_nodes;
                        var_stack.insert(begin(var_stack), size_nodes, 0.0);
                        //
                        // Добавляем все дочерние элементы
                        //
                        for (auto it(rbegin(node->Nodes)); it != rend(node->Nodes); it++)
                        {
                            node_stack.push_back(pair((*it)->Nodes.empty(), *it));
                        }
                    }
                    break;
                    //
                    // Обработка ветвления
                    //
                case TActionType::If:
                    {
                        auto condition(FRONT(node->Nodes));
                        node_stack.push_back(pair(condition->Nodes.empty(), condition));
                    }
                    break;
                    //
                    // Обработка цикла while
                    //
                case TActionType::While:
                    {
                        auto condition(FRONT(node->Nodes));
                        node_stack.push_back(pair(condition->Nodes.empty(), condition));
                    }
                    break;
                    //
                    // Обработка цикла for
                    //
                case TActionType::For:
                    {
                        auto for_init(node->Nodes.at(0));
                        auto condition(node->Nodes.at(1));

                        node_stack.push_back(pair(condition->Nodes.empty(), condition));

                        if (node->Index < 0)
                        {
                            node_stack.push_back(pair(for_init->Nodes.empty(), for_init));
                        }
                    }
                    break;
                    //
                    // Обработка функции
                    //
                case TActionType::Function:
                    {
                        //
                        // Добавляем дочерние аргументы, пропускаем узел FunctionArguments
                        //
                        for (auto it(rbegin(node->Nodes)); it != rend(node->Nodes); it++)
                        {
                            if (!(*it)->Is(TActionType::FunctionArguments))
                            {
                                node_stack.push_back(pair((*it)->Nodes.empty(), *it));
                            }
                        }
                    }
                    break;
                    //
                    // Добавляем все дочерние элементы по умолчанию
                    //
                default:
                    {
                        for (auto it(rbegin(node->Nodes)); it != rend(node->Nodes); it++)
                        {
                            node_stack.push_back(pair((*it)->Nodes.empty(), *it));
                        }
                    }
                    break;
                }
            }
        }
        //
        // Очистка стека счётчиков переменных
        //
        var_counter_stack.clear();
        //
        // Очистка стека результата
        //
        result_stack.clear();
        //
        // Очистка стека переменных
        //
        var_stack.clear();
        //
        // Очистка стека узлов
        //
        node_stack.clear();
        //
        // Если обнаружена ошибка меняем результирующее значение
        //
        if (!IsValid(result))
        {
            result = err_value;
            return false;
        }
        else
        {
            return !AreSame<double>(result, err_value);
        }
    }

    return false;
}
// ---------------------------------------------------------------------------
//
// Указатель на дерево разбора
//
std::shared_ptr<TActionNode> TInterpreter::GetParseTree() { return root; }
// ---------------------------------------------------------------------------
//
// Копия глобального массива
//
void TInterpreter::GetGlobalArray(std::vector<double>& _global_array)
{
    copy(begin(global_array), end(global_array), back_inserter(_global_array));
}
// ---------------------------------------------------------------------------
