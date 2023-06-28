#include "action_tree.hpp"
// ---------------------------------------------------------------------------
#include <fw_base.hpp>
// ---------------------------------------------------------------------------
using namespace std;
using namespace CalcPlusPlus;
// ---------------------------------------------------------------------------
using TSFormater = Framework::String::TFormater<std::string>;
using TSExtension = Framework::String::TExtension<std::string>;
// ---------------------------------------------------------------------------
#define BREAK_ERROR                     "Оператор break должен использоваться в теле цикла."
#define FUNCTION_ARGS_ERROR             "Обнаружено совпадение имён аргументов в функции {0}. Имя аргумента {1}."
#define FUNCTION_VARS_ERROR             "Обнаружено совпадение имени переменной {0} с аргументом функции или с другой переменной. Функция {1}."
#define FUNCTION_VARS_INIT_ERROR        "Обнаружен неизвестный идентификатор {0} при инициализации переменной {1} в теле функции {2}."
#define FUNCTION_MAIN_ERROR             "Неизвестный идентификатор {0} в теле функции {1}."
#define FUNCTION_NAME_ERROR             "Обнаружено совпадение имён функций. Имя функции {0}. Количество аргументов {1}."
#define FUNCTION_INVOKE_DECL_ERROR      "Обнаружен вызов необъявленной функции {0}. Количество аргументов {1}."
#define MAIN_VARS_ERROR                 "Обнаружено совпадение имён переменных в теле основной программы. Переменная {0}."
#define MAIN_TREE_ERROR                 "Обнаружена критическая ошибка в структуре дерева разбора"
#define CHECK_ALL_ID_ERROR              "Критическая ошибка! Обнаружен идентификатор не прошедший инициализацию. Идентификатор: {0}." 
#define CHECK_ALL_EXT_ID_ERROR          "Критическая ошибка! Идентификатор отсутствует в списке внешних переменных. Идентификатор: {0}."
#define CHECK_ALL_FUNC_DEF_ERROR        "Критическая ошибка! Не удалось определить вызываемую функцию. Имя вызываемой функции: {0}."
#define CHECK_ALL_FUNC_NAMES_ERROR      "Критическая ошибка! Вызов функции {0} ссылается на функцию с другим именем {1}."
// ---------------------------------------------------------------------------
static vector<TActionType> vector_action_types = {
    TActionType::Program,
    TActionType::Main,
    TActionType::BlockCode,
    TActionType::FunctionArguments,
    TActionType::Undefined,
    TActionType::Empty,
    TActionType::Identifier,
    TActionType::Number,

    TActionType::Plus,
    TActionType::Minus,
    TActionType::Multiplication,
    TActionType::Division,
    TActionType::Bigger,
    TActionType::Smaller,
    TActionType::EqualEqual,
    TActionType::NotEqual,
    TActionType::LessOrEqual,
    TActionType::GreatOrEqual,
    TActionType::And,
    TActionType::Or,
    TActionType::Assignment,
    TActionType::PlusPlus,
    TActionType::MinusMinus,
    TActionType::PlusAssignment,
    TActionType::MinusAssignment,
    TActionType::MultAssignment,
    TActionType::DivisionAssignment,

    TActionType::True,
    TActionType::False,

    TActionType::Variables,
    TActionType::Var,
    TActionType::If,
    TActionType::Else,
    TActionType::TrueBlock,
    TActionType::FalseBlock,
    TActionType::While,
    TActionType::DoWhile,
    TActionType::For,
    TActionType::Break,

    TActionType::Options,
    TActionType::OptErrorValue,
    TActionType::OptLoopLimit,

    TActionType::Pi,
    TActionType::ErrorValue,
    TActionType::IsErrorValue,
    TActionType::IfErrValueDef,
    TActionType::Ln,
    TActionType::Lg,
    TActionType::Sin,
    TActionType::Cos,
    TActionType::Tan,
    TActionType::CoTan,
    TActionType::Sec,
    TActionType::Csc,
    TActionType::ASin,
    TActionType::ACos,
    TActionType::ATan,
    TActionType::ACoTan,
    TActionType::ASec,
    TActionType::ACsc,
    TActionType::SinH,
    TActionType::CosH,
    TActionType::TanH,
    TActionType::CoTanH,
    TActionType::SecH,
    TActionType::CscH,
    TActionType::ASinH,
    TActionType::ACosH,
    TActionType::ATanH,
    TActionType::ACoTanH,
    TActionType::ASecH,
    TActionType::ACscH,
    TActionType::Abs,
    TActionType::Sqrt,
    TActionType::Int,
    TActionType::Frac,
    TActionType::Sqr,
    TActionType::Cube,
    TActionType::Round,
    TActionType::Fact,
    TActionType::Pow,
    TActionType::Inc,
    TActionType::Dec,
    TActionType::Sum,
    TActionType::Max,
    TActionType::Min,
    TActionType::Avg,
    TActionType::Prod,
    TActionType::Poly,

    TActionType::Void_ArrayInit,
    TActionType::Void_ArrayInitIfEmpty,
    TActionType::ArraySize,
    TActionType::Void_ArrayClear,
    TActionType::Void_ArrayPushBack,
    TActionType::Void_ArrayPushFront,
    TActionType::Void_ArrayPopBack,
    TActionType::Void_ArrayPopFront,
    TActionType::Void_ArrayAt,
    TActionType::ArrayAt,
    TActionType::ArrayFront,
    TActionType::ArrayBack,
    TActionType::Void_ArrayInsert,
    TActionType::Void_ArrayErase,
    TActionType::Void_ArrayEraseValue,
    TActionType::Void_ArrayResize,
    TActionType::Void_ArraySort,
    TActionType::Void_ArrayReverse,
    TActionType::Void_ArrayUnique,
    TActionType::ArrayProd,
    TActionType::ArrayAvg,
    TActionType::ArrayMin,
    TActionType::ArrayMax,
    TActionType::ArraySum,
    TActionType::ArrayPoly,

    TActionType::Functions,
    TActionType::InvokeFunction,
    TActionType::Function
};
static vector<string> vector_action_strings = {
    "Program",
    "Main",
    "BlockCode",
    "FunctionArguments",
    "Undefined",
    "Empty",
    "Identifier",
    "Number",

    "+",
    "-",
    "*",
    "/",
    ">",
    "<",
    "==",
    "!=",
    "<=",
    ">=",
    "&&",
    "||",
    "=",
    "++",
    "--",
    "+=",
    "-=",
    "*=",
    "/=",

    "True",
    "False",

    "Variables",
    "Var",
    "If",
    "Else",
    "TrueBlock",
    "FalseBlock",
    "While",
    "DoWhile",
    "For",
    "Break",

    "Options",
    "#error_value",
    "#loop_limit",

    "Pi",
    "ErrorValue",
    "IsErrorValue",
    "IfErrValueDef",
    "Ln",
    "Lg",
    "Sin",
    "Cos",
    "Tan",
    "CoTan",
    "Sec",
    "Csc",
    "ASin",
    "ACos",
    "ATan",
    "ACoTan",
    "ASec",
    "ACsc",
    "SinH",
    "CosH",
    "TanH",
    "CoTanH",
    "SecH",
    "CscH",
    "ASinH",
    "ACosH",
    "ATanH",
    "ACoTanH",
    "ASecH",
    "ACscH",
    "Abs",
    "Sqrt",
    "Int",
    "Frac",
    "Sqr",
    "Cube",
    "Round",
    "Fact",
    "Pow",
    "Inc",
    "Dec",
    "Sum",
    "Max",
    "Min",
    "Avg",
    "Prod",
    "Poly",

    "void_ArrayInit",
    "void_ArrayInitIfEmpty",
    "ArraySize",
    "void_ArrayClear",
    "void_ArrayPushBack",
    "void_ArrayPushFront",
    "void_ArrayPopBack",
    "void_ArrayPopFront",
    "void_ArrayAt",
    "ArrayAt",
    "ArrayFront",
    "ArrayBack",
    "void_ArrayInsert",
    "void_ArrayErase",
    "void_ArrayEraseValue",
    "void_ArrayResize",
    "void_ArraySort",
    "void_ArrayReverse",
    "void_ArrayUnique",
    "ArrayProd",
    "ArrayAvg",
    "ArrayMin",
    "ArrayMax",
    "ArraySum",
    "ArrayPoly",

    "Functions",
    "Function",
    "InvokeFunction"
};
// ---------------------------------------------------------------------------
#pragma region Functions // Набор вспомогательных функций
namespace
{
    //
    // Преобразование TActionType в std::string
    //
    std::string ActionTypeToString(TActionType type)
    {
        return TSExtension::Compare(type, vector_action_types, vector_action_strings, "");
    }
// ---------------------------------------------------------------------------
    //
    // Поиск раздела функций в дереве разбора
    //
    shared_ptr<TActionNode> FindFunctions(shared_ptr<TActionNode> root)
    {
        if (root && root->Is(TActionType::Program))
        {
            if (auto it = find_if(begin(root->Nodes), end(root->Nodes), [](shared_ptr<TActionNode> value) { return value->Is(TActionType::Functions); }); it != end(root->Nodes))
            {
                return *it;
            }

        }
        return nullptr;
    }
// ---------------------------------------------------------------------------
    //
    // Поиск аргументов в функции
    //
    shared_ptr<TActionNode> FindFunctionArgs(shared_ptr<TActionNode> func)
    {
        if (func && func->Is(TActionType::Function))
        {
            if (auto it = find_if(begin(func->Nodes), end(func->Nodes), [](shared_ptr<TActionNode> value) { return value->Is(TActionType::FunctionArguments); }); it != end(func->Nodes))
            {
                return *it;
            }
        }
        return nullptr;
    }
// ---------------------------------------------------------------------------
    //
    // Поиск функции по имени и количеству аргументов
    //
    shared_ptr<TActionNode> FindFunction(shared_ptr<TActionNode> functions, const string& name, size_t args)
    {
        if (functions && functions->Is(TActionType::Functions))
        {
            auto it = find_if(begin(functions->Nodes), end(functions->Nodes), [&](shared_ptr<TActionNode> value) {
                auto function_args = FindFunctionArgs(value);
                size_t _args = function_args ? size(function_args->Nodes) : 0;
                return TSExtension::Compare(value->Name, name, true) && (_args == args);
            });

            return it != end(functions->Nodes) ? *it : nullptr;
        }
        return nullptr;
    }
// ---------------------------------------------------------------------------
    //
    // Поиск переменных в функции
    //
    shared_ptr<TActionNode> FindFunctionVars(shared_ptr<TActionNode> func)
    {
        if (func && func->Is(TActionType::Function))
        {
            if (auto it = find_if(begin(func->Nodes), end(func->Nodes), [](shared_ptr<TActionNode> value) { return value->Is(TActionType::Variables); }); it != end(func->Nodes))
            {
                return *it;
            }
        }
        return nullptr;
    }
// ---------------------------------------------------------------------------
    //
    // Поиск блока с кодом функции
    //
    shared_ptr<TActionNode> FindFunctionMain(shared_ptr<TActionNode> func)
    {
        if (func && func->Is(TActionType::Function))
        {
            if (auto it = find_if(begin(func->Nodes), end(func->Nodes), [](shared_ptr<TActionNode> value) { return value->Is(TActionType::Main); }); it != end(func->Nodes))
            {
                return *it;
            }
        }
        return nullptr;
    }
// ---------------------------------------------------------------------------
    //
    // Поиск списка переменных основной программы
    //
    shared_ptr<TActionNode> FindProgramVars(shared_ptr<TActionNode> root)
    {
        if (root && root->Is(TActionType::Program))
        {
            auto it = find_if(begin(root->Nodes), end(root->Nodes), [](shared_ptr<TActionNode> value) { return value->Is(TActionType::Variables); });

            return it != end(root->Nodes) ? *it : nullptr;
        }
        return nullptr;
    }
// ---------------------------------------------------------------------------
    //
    // Поиск основного узла программы
    //
    shared_ptr<TActionNode> FindProgramMain(shared_ptr<TActionNode> root)
    {
        if (root && root->Is(TActionType::Program))
        {
            auto it = find_if(begin(root->Nodes), end(root->Nodes), [](shared_ptr<TActionNode> value) { return value->Is(TActionType::Main); });

            return it != end(root->Nodes) ? *it : nullptr;
        }
        return nullptr;
    }
    //
    // Поиск имени переменной в стеке
    //
    int64_t FindInStack(const vector<std::string>& stack, const string& name)
    {
        auto it = find_if(begin(stack), end(stack), [&name](const string& value) { return TSExtension::Compare(value, name, true); });
        return it != end(stack) ? static_cast<int64_t>(distance(begin(stack), it)) : -1;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка аргументов функции
    // Функция добавляет в стек аргументы
    // Проверяет наличие совпадений имён аргументов функции
    //
    bool CheckFunctionArgs(shared_ptr<TActionNode> func, vector<string>& stack, string& error)
    {
        if (func && func->Is(TActionType::Function))
        {
            if (shared_ptr<TActionNode> args(FindFunctionArgs(func)); args)
            {
                //
                // Цикл по аргументам функции
                //
                for (auto arg : args->Nodes)
                {
                    //
                    // Ошибка, совпадение аргументов функции
                    //
                    if (FindInStack(stack, arg->Name) >= 0)
                    {
                        error = TSFormater::Format(FUNCTION_ARGS_ERROR, func->Name, arg->Name);
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                    //
                    // Добавляем аргумент в стек
                    //
                    stack.push_back(arg->Name);
                }
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка идентификаторов при инициализации переменных в функции
    //
    bool CheckFunctionVarInit(shared_ptr<TActionNode> node, vector<string>& stack, string& identifier)
    {
        if (node)
        {
            if (node->Is(TActionType::Identifier))
            {
                if (FindInStack(stack, node->Name) < 0)
                {
                    identifier = node->Name;
                    return false;
                }
            }

            for (auto _node : node->Nodes)
            {
                if (!CheckFunctionVarInit(_node, stack, identifier)) return false;
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка переменных функции
    // Функция добавляет в стек переменные
    // Проверяет наличие совпадений имён аргументов и переменных функций
    //
    bool CheckFunctionVars(shared_ptr<TActionNode> func, vector<string>& stack, string& error)
    {
        if (func && func->Is(TActionType::Function))
        {
            if (shared_ptr<TActionNode> vars(FindFunctionVars(func)); vars)
            {
                //
                // Цикл по переменным функции
                //
                for (auto var : vars->Nodes)
                {
                    auto _var(var->Nodes.front());
                    //
                    // Ошибка, совпадение переменной с другой переменной в стеке или аргументом
                    //
                    if (FindInStack(stack, _var->Name) >= 0)
                    {
                        error = TSFormater::Format(FUNCTION_VARS_ERROR, _var->Name, func->Name);
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                    //
                    // Проверка выражения инициализации переменной
                    //
                    if ((size(var->Nodes) > 1) && !CheckFunctionVarInit(var->Nodes.back(), stack, error))
                    {
                        error = TSFormater::Format(FUNCTION_VARS_INIT_ERROR, error, _var->Name, func->Name);
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                    //
                    // Добавление переменной в стек
                    //
                    stack.push_back(_var->Name);
                }
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка идентификаторов в коде функции
    //
    bool CheckFunctionMain(shared_ptr<TActionNode> node, vector<string>& stack, const string& function_name, string& error)
    {
        if (node)
        {
            if (node->Is(TActionType::Identifier))
            {
                if (FindInStack(stack, node->Name) < 0)
                {
                    error = TSFormater::Format(FUNCTION_MAIN_ERROR, node->Name, function_name);
                    VOID_AUTO_ENCODING(string, error);
                    return false;
                }
            }

            for (auto _node : node->Nodes)
            {
                if (!CheckFunctionMain(_node, stack, function_name, error)) return false;
            }

            return true;
        }
        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка идентификаторов при инициализации переменных в основной программе
    //
    bool CheckMainIdentifier(shared_ptr<TActionNode> node, TExternalIdList& external_identifiers, vector<string>& stack, vector<int64_t>& stack_index)
    {
        if (node)
        {
            //
            // Найден идентификатор
            //
            if (string node_name(node->Name); node->Is(TActionType::Identifier))
            {
                //
                // Проверка наличия переменной в стеке
                //
                if (int64_t index(FindInStack(stack, node_name)); index >= 0)
                {
                    node->Index = stack_index.at(static_cast<size_t>(index));
                }
                else // Проверка наличия идентификатора в списке внешних переменных
                {
                    auto it = find_if(begin(external_identifiers), end(external_identifiers), [&node_name](const pair<string, shared_ptr<double>>& value) { return TSExtension::Compare(value.first, node_name, true); });
                    //
                    // Идентификатор найден в списке внешних переменных
                    //
                    if (it != end(external_identifiers))
                    {
                        node->ExternalID = it->second;
                    }
                    else // Идентификатор не найден, добавляем новую внешнюю переменную
                    {
                        node->ExternalID = make_shared<double>(0);
                        external_identifiers.push_back(pair(node->Name, node->ExternalID));
                    }
                }
            }
            //
            // Цикл по дочерним узлам
            //
            for (auto _node : node->Nodes)
            {
                if (!CheckMainIdentifier(_node, external_identifiers, stack, stack_index)) return false;
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка переменных основной программы
    //
    bool CheckMainVars(shared_ptr<TActionNode> vars, TExternalIdList& external_identifiers, string& error, vector<string>& stack, vector<int64_t>& stack_index)
    {
        if (vars && vars->Is(TActionType::Variables))
        {
                //
                // Цикл по переменным
                //
                for (auto var : vars->Nodes)
                {
                    auto _var(var->Nodes.front());
                    //
                    // Ошибка, совпадение имён переменных
                    //
                    if (FindInStack(stack, _var->Name) >= 0)
                    {
                        error = TSFormater::Format(MAIN_VARS_ERROR, _var->Name);
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                    //
                    // Установка индекса для переменной
                    //
                    _var->Index = size(vars->Nodes) - size(stack) - 1;
                    //
                    // Добавление переменной в стек
                    //
                    stack.push_back(_var->Name);
                    stack_index.push_back(_var->Index);
                    //
                    // Проверка выражения инициализации переменной
                    //
                    if ((size(var->Nodes) > 1) && !CheckMainIdentifier(var->Nodes.back(), external_identifiers, stack, stack_index))
                    {
                        error = MAIN_TREE_ERROR;
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                }


            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
// ***************************************************************************
// ---------------------------------------------------------------------------
    //
    // Проверка корректность использование оператора break
    //
    bool CheckBreakOperator(shared_ptr<TActionNode> root, string& error, shared_ptr<vector<TActionType>> stack = nullptr)
    {
        if (stack == nullptr)
        {
            stack = make_shared<vector<TActionType>>();
        }

        if (root->Is(TActionType::Break))
        {
            auto it = find_if(rbegin(*stack), rend(*stack), [](TActionType type)
            {
                return (type == TActionType::For) || (type == TActionType::While) || (type == TActionType::DoWhile);
            });
            //
            // Ошибка, оператор break используется не в теле цикла
            //
            if (it == rend(*stack))
            {
                error = BREAK_ERROR;
                VOID_AUTO_ENCODING(string, error);
                return false;

            }
        }

        stack->push_back(root->Type);

        for (auto node : root->Nodes)
        {
            if (!CheckBreakOperator(node, error, stack)) return false;
        }

        stack->pop_back();

        return true;
    }
    //
    // ПРОВЕРКА НА СОВПАДЕНИЕ ИМЁН ФУНКЦИЙ
    //
    bool CheckFunctionNames(shared_ptr<TActionNode> root, string& error)
    {
        if (root && root->Is(TActionType::Program))
        {
            //
            // Поиск списка функций
            //
            if (shared_ptr<TActionNode> functions(FindFunctions(root)); functions)
            {
                vector<string> stack;
                //
                // Цикл по списку функций
                //
                for (auto func : functions->Nodes)
                {
                    size_t num_args(0);
                    //
                    // Функция содержит аргументы
                    //
                    if (shared_ptr<TActionNode> f_args(FindFunctionArgs(func)); f_args)
                    {
                        num_args = size(f_args->Nodes);
                    }
                    //
                    // Формирование имени функции
                    //
                    string function_name = TSFormater::Concatenate(func->Name, "_", num_args);
                    //
                    // Ошибка, обнаружено совпадение имён функций
                    //
                    if (FindInStack(stack, function_name) >= 0)
                    {
                        error = TSFormater::Format(FUNCTION_NAME_ERROR, func->Name, num_args);
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                    //
                    // Добавляем функцию в стек
                    //
                    stack.push_back(function_name);
                }
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка идентификаторов функций
    // Аргументы и переменные в функции не должны совпадать между собой.
    // Идентификаторы в теле функции должны быть определены в аргументах или переменных функции.
    //
    bool CheckFunctionIdentifiers(shared_ptr<TActionNode> root, string& error)
    {
        //
        // Выход если узел не проинициализирован
        //
        if (root && root->Is(TActionType::Program))
        {
            //
            // Поиск функций в корне дерева
            //
            if (shared_ptr<TActionNode> functions(FindFunctions(root)); functions)
            {
                vector<string> stack;
                //
                // Цикл по функциям
                //
                for (auto func : functions->Nodes)
                {
                    //
                    // Очистка стека
                    //
                    stack.clear();
                    //
                    // ПОИСК АРГУМЕНТОВ ФУНКЦИИ
                    //
                    if (!CheckFunctionArgs(func, stack, error)) return false;
                    //
                    // ПОИСК ПЕРЕМЕННЫХ ФУНКЦИИ
                    //
                    if (!CheckFunctionVars(func, stack, error)) return false;
                    //
                    //  ПОИСК ИДЕНТИФИКАТОРОВ В КОДЕ ФУНКЦИИ
                    //
                    if (shared_ptr<TActionNode> main(FindFunctionMain(func)); main)
                    {
                        if (!CheckFunctionMain(main, stack, func->Name, error)) return false;
                    }
                }
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Инициализация индексов идентификаторов в стеке
    // Для каждого аргумента и идентификатора выставляется ожидаемый индекс в стеке переменных
    // !!!ВНИМАНИЕ!!! Проверка на ошибки при объявлении аргументов и переменных функции проводится функцией CheckFunctionIdentifiers перед вызовом данной функции
    //
    bool SetFunctionIdIndex(shared_ptr<TActionNode> root, shared_ptr<vector<string>> stack = nullptr)
    {
        //
        // Выход если узел не проинициализирован
        //
        if (root)
        {
            //
            // Первый вызов, инициализация
            //
            if (root->Is(TActionType::Program) && (stack == nullptr))
            {
                //
                // Инициализация стека
                //
                stack = make_shared<std::vector<string>>();
                //
                // Поиск функций в корне дерева
                //
                if (shared_ptr<TActionNode> functions(FindFunctions(root)); functions)
                {
                    //
                    // Цикл по функциям
                    //
                    for (auto func : functions->Nodes)
                    {
                        shared_ptr<TActionNode> vars(nullptr), args(nullptr);
                        //
                        // Очистка стека
                        //
                        stack->clear();
                        //
                        // Инициализация счётчика вызова функций
                        //
                        func->Index = 0;
                        //
                        // ПОИСК ПЕРЕМЕННЫХ ФУНКЦИИ
                        //
                        if (vars = FindFunctionVars(func); vars)
                        {
                            //
                            // Цикл по переменным функции (!!!ВАЖНО!!! С конца в начало!!!)
                            //
                            for (auto it(rbegin(vars->Nodes)); it != rend(vars->Nodes); it++)
                            {
                                auto var((*it)->Nodes.front());

                                var->Index = size(*stack);

                                stack->push_back(var->Name);
                            }
                        }
                        //
                        // ПОИСК АРГУМЕНТОВ ФУНКЦИИ
                        //
                        if (args = FindFunctionArgs(func); args)
                        {
                            //
                            // Цикл по аргументам функции (!!!ВАЖНО!!! С конца в начало!!!)
                            //
                            for (auto it(rbegin(args->Nodes)); it != rend(args->Nodes); it++)
                            {
                                auto arg(*it);

                                arg->Index = size(*stack);

                                stack->push_back(arg->Name);
                            }
                        }
                        //
                        // ПРОВЕРКА ВЫРАЖЕНИЯ ИНИЦИАЛИЗАЦИИ ПЕРЕМЕННОЙ
                        //
                        if (vars)
                        {
                            for (auto var : vars->Nodes)
                            {
                                if ((size(var->Nodes) > 1))
                                {
                                    SetFunctionIdIndex(var->Nodes.back(), stack);
                                }
                            }
                        }
                        //
                        // ПОИСК ИДЕНТИФИКАТОРОВ В КОДЕ ФУНКЦИИ
                        //
                        if (shared_ptr<TActionNode> main(FindFunctionMain(func)); main)
                        {
                            for(auto node : main->Nodes)
                            {
                                SetFunctionIdIndex(node, stack);
                            }
                        }
                    }
                }
            }
            else // Повторный вызов, рекурсия
            {
                //
                // Найден идентификатор
                //
                if (root->Is(TActionType::Identifier))
                {
                    root->Index = FindInStack(*stack, root->Name);
                }
                //
                // Цикл по дочерним узлам
                //
                for (auto node : root->Nodes)
                {
                    SetFunctionIdIndex(node, stack);
                }
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка корректности вызовов функций
    //
    bool CheckFunctionInvokes(shared_ptr<TActionNode> root, string& error, shared_ptr<TActionNode> functions = nullptr)
    {
        if (root)
        {
            //
            // Первый вызов функции
            //
            if (root->Is(TActionType::Program) && (functions == nullptr))
            {
                //
                // Поиск функций
                //
                functions = FindFunctions(root);
                //
                // Цикл по дочерним узлам дереве
                //
                for (auto node : root->Nodes)
                {
                    if (!CheckFunctionInvokes(node, error, functions)) return false;
                }
            }
            else // Рекурсия
            {
                //
                // Обнаружен вызов функции
                //
                if (root->Is(TActionType::InvokeFunction))
                {
                    if (functions)
                    {
                        //
                        // Найдена вызываемая функций
                        //
                        if (auto func(FindFunction(functions, root->Name, size(root->Nodes))); func)
                        {
                            //
                            // Сохраняем указатель на вызываемую функцию
                            //
                            root->Invoke = func;
                        }
                        else // Ошибка, вызов несуществующей функции
                        {
                            error = TSFormater::Format(FUNCTION_INVOKE_DECL_ERROR, root->Name, size(root->Nodes));
                            VOID_AUTO_ENCODING(string, error);
                            return false;
                        }
                    }
                    else // Ошибка, вызов несуществующей функции
                    {
                        error = TSFormater::Format(FUNCTION_INVOKE_DECL_ERROR, root->Name, size(root->Nodes));
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                }
                //
                // Цикл по дочерним узлам в дереве
                //
                for (auto node : root->Nodes)
                {
                    if (!CheckFunctionInvokes(node, error, functions)) return false;
                }
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Проверка идентификаторов в основном узле дерева разбора
    //
    bool CheckMain(shared_ptr<TActionNode> root, TExternalIdList& external_identifiers, string& error)
    {
        if (root && root->Is(TActionType::Program))
        {
            vector<string> stack;
            vector<int64_t> stack_index;
            //
            // ПРОВЕРКА ПЕРЕМЕННЫХ ОСНОВНОЙ ПРОГРАММЫ
            //
            if (shared_ptr<TActionNode> vars(FindProgramVars(root)); vars)
            {
                if (!CheckMainVars(vars, external_identifiers, error, stack, stack_index)) return false;
            }
            //
            // ПРОВЕРКА ИДЕНТИФИКАТОРОВ В ТЕЛЕ ОСНОВНОЙ ПРОГРАММЫ
            //
            if (shared_ptr<TActionNode> main(FindProgramMain(root)); main)
            {
                if (!CheckMainIdentifier(main, external_identifiers, stack, stack_index)) return false;
            }

            return true;
        }

        return false;
    }
// ---------------------------------------------------------------------------
    //
    // Дополнительная проверка всего дерева разбора
    //
    bool CheckAll(shared_ptr<TActionNode> root, TExternalIdList& external_identifiers, string& error)
    {
        if (root)
        {
            //
            // Идентификатор
            //
            if (root->Is(TActionType::Identifier))
            {
                if (root->Index < 0)
                {
                    //
                    // Поиск идентификатора в списке внешних переменных
                    //
                    if (string name(root->Name); root->ExternalID)
                    {
                        shared_ptr<double> external_id(root->ExternalID);
                        auto it = find_if(begin(external_identifiers), end(external_identifiers), [&name, external_id](pair<string, shared_ptr<double>>& value)
                        {
                            return TSExtension::Compare(value.first, name, true) && (value.second.get() == external_id.get());
                        });
                        //
                        // Ошибка идентификатор отсутствует в списке внешних переменных
                        //
                        if (it == end(external_identifiers))
                        {
                            error = TSFormater::Format(CHECK_ALL_EXT_ID_ERROR, name);
                            VOID_AUTO_ENCODING(string, error);
                            return false;
                        }
                    }
                    else // Ошибка, не проинициализирован идентификатор
                    {
                        error = TSFormater::Format(CHECK_ALL_ID_ERROR, name);
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                }
            }
            //
            // Вызов функции
            //
            if (root->Is(TActionType::InvokeFunction))
            {
                //
                // Сравнение имён функций
                //
                if (root->Invoke)
                {
                    //
                    // Ошибка, имена функций не совпадают
                    //
                    if (!TSExtension::Compare(root->Name, root->Invoke->Name, true))
                    {
                        error = TSFormater::Format(CHECK_ALL_FUNC_NAMES_ERROR, root->Name, root->Invoke->Name);
                        VOID_AUTO_ENCODING(string, error);
                        return false;
                    }
                }
                else // Ошибка, вызов функции которую не удалось определить
                {
                    error = TSFormater::Format(CHECK_ALL_FUNC_DEF_ERROR, root->Name);
                    VOID_AUTO_ENCODING(string, error);
                    return false;
                }
            }
            //
            // Проход по дочерним элементам
            //
            for (auto node : root->Nodes)
            {
                if (!CheckAll(node, external_identifiers, error)) return false;
            }

            return true;
        }

        return false;
    }
}
#pragma endregion
// ---------------------------------------------------------------------------
#pragma region TActionNode // Структура описывает узел дерева разбора
//
// Конструктор 1
//
TActionNode::TActionNode(TActionType type) : Type(type), Name(ActionTypeToString(type)), Number(0.0), Index(-1), ExternalID(nullptr), Invoke(nullptr) {}
// ---------------------------------------------------------------------------
//
// Конструктор 2
//
TActionNode::TActionNode() : TActionNode(TActionType::Undefined) {}
// ---------------------------------------------------------------------------
//
// Конструктор 3
//
TActionNode::TActionNode(double number) : TActionNode(TActionType::Number)
{
    Number = number;
}
// ---------------------------------------------------------------------------
//
// Конструктор 4
//
TActionNode::TActionNode(TActionType type, const std::string& name) : TActionNode(type)
{
    Name = name;
}
// ---------------------------------------------------------------------------
//
// Добавление дочернего узла
//
void TActionNode::AddNode(std::shared_ptr<TActionNode> node, bool back)
{
    if (node)
    {
        Nodes.insert(back ? std::end(Nodes) : std::begin(Nodes), node);
    }
}
// ---------------------------------------------------------------------------
//
// Добавление дочерних узлов из списка
//
void TActionNode::AddNodes(const std::vector<std::shared_ptr<TActionNode>>& nodes, bool back)
{
    Nodes.insert(back ? end(Nodes) : begin(Nodes), begin(nodes), end(nodes));
}
// ---------------------------------------------------------------------------
//
// Установка типа узла
//
void TActionNode::Set(TActionType type, bool reinit_name)
{
    Type = type;

    if (reinit_name)
    {
        Name = ActionTypeToString(type);
    }
}
// ---------------------------------------------------------------------------
//
// Проверка типа узла
//
bool TActionNode::Is(TActionType type)
{
    return Type == type;
}
// ---------------------------------------------------------------------------
//
// Семантический анализ дерева разбора
//
std::shared_ptr<TActionNode> TActionNode::SemanticCheck(std::shared_ptr<TActionNode> root, TExternalIdList& external_identifiers, std::string& error)
{
    return CheckBreakOperator(root, error)                  // Проверка оператора Break
            && CheckFunctionNames(root, error)              // Проверка на совпадение имён функций
            && CheckFunctionIdentifiers(root, error)        // Проверка на наличие всех идентификаторов в функции
            && SetFunctionIdIndex(root)                     // Установка индексов стека для доступа к данным переменных в функции
            && CheckFunctionInvokes(root, error)            // Проверка корректности вызова функций
            && CheckMain(root, external_identifiers, error) // Проверка идентификаторов основной программы
            && CheckAll(root, external_identifiers, error)  // Дополнительная проверка всего дерева разбора
            ? root : nullptr;
}
#pragma endregion
// ---------------------------------------------------------------------------
