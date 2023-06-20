%require "3.2"                                  // Минимальная версия bison
%skeleton "lalr1.cc"                            // Грамматика LALR(1)
%language "c++"                                 // Язык c++


%define api.namespace {CalcPlusPlus}            // Пространство имён CalcPlusPlus
%define api.parser.class {TParser}              // Имя класса парсера TParser


%define api.value.type variant                  // Использование объектов C++ в качестве данных токена
%define api.token.constructor                   // В сочетании с параметром "api.value.type variant" устанавливает возвращаемый тип symbol_type для функции лексера yylex. Содержит данные токена и его положение во входном потоке символов. 
%define parse.error verbose                     // Подробный режим вывода описания ошибки при разборе набора входных токенов


%header "parser.hpp"                            // Заголовочный файл парсера
%output "parser.cpp"                            // Файл с исходным кодом парсера


%locations                                      // Генерировать заголовочный файл location
%define api.location.file "location.hpp"        // Имя заголовочного файла location


//
// Входные параметры конструктора класса CalcPlusPlus::TParser
//
%parse-param {CalcPlusPlus::TScanner& lexer}    // Лексический анализатор (сканер для формирования набора токенов)
%parse-param {CalcPlusPlus::TActionNode& root}  // Корневой узел синтаксического дерева
%parse-param {std::string& error_msg}           // Описание ошибки при разборе набора входных токенов


%define api.token.prefix {TOKEN_}               // Префикс который добавляется к имени токена
//%expect 1                                       // Ожидается конфликт shift/reduce (сдвиг/свёртка). Не выводить предупреждение

//
// Код который добавляется в заголовочный файл парсера (parser.hpp)
//
%code requires {
    //
    // Модуль описывает синтаксическое дерево
    //
    #include "action_tree.hpp"
    //
    // Пространство имён в котором находится класс лексического анализатора (сканера)
    //
    namespace CalcPlusPlus
    {
        class TScanner; // Объявляем класс лексического анализатора
    }
    //
    // Отключение предупреждений компилятора для WINDOWS
    //
#ifdef WINDOWS
    #pragma warning(disable:4065)
#endif
}


//
// Код который добавляется в файл с исходным кодом парсера (parser.cpp)
//
%code {
    //
    // Заголовочный файл с вспомогательными шаблонами и функциями
    //
    #include <fw_base.hpp>
    //
    // Заголовочный файл лексического анализатора (сканера)
    //
    #include "scanner.hpp"
    //
    // Главная функция лексического анализатора, которая возвращает описание токена с его положением во входном потоке символов
    // Ссылаемся на метод lex класса класса lexer. Имя класса указывается в директиве %parse-param {CalcPlusPlus::TScanner& lexer} (!!должны совпадать!!!)
    //
    #undef yylex
    #define yylex lexer.lex
}


//
// Объявление токенов
//
%token <double> NUMBER "double constant";
%token <std::string> IDENTIFIER "Identifier";
%token EOF 0 "end of file";

%token '+' '-' '*' '/' ';' '(' ')' '#';

%token
    TRUE_CONST                  "true"
    FALSE_CONST                 "false"
    FUNCTION                    "function"
    VAR                         "var"
    IF                          "if"
    ELSE                        "else"
    WHILE                       "while"
    DO_WHILE                    "do"
    FOR                         "for"
    BREAK                       "break"
    OPT_ERRORVALUE              "error_value"
    OPT_LOOPLIMIT               "loop_limit"
    BF_PI                       "Pi"
    BF_ERRORVALUE               "ErrorValue"
    BF_ISERRORVALUE             "IsErrorValue"
    BF_IFERRORVALUEDEF          "IfErrorValueDef"
    BF_LN                       "Ln"
    BF_LG                       "Lg"
    BF_SIN                      "Sin"
    BF_COS                      "Cos"
    BF_TAN                      "Tan"
    BF_COTAN                    "CoTan"
    BF_SEC                      "Sec"
    BF_CSC                      "Csc"
    BF_ASIN                     "ASin"
    BF_ACOS                     "ACos"
    BF_ATAN                     "ATan"
    BF_ACOTAN                   "ACoTan"
    BF_ASEC                     "ASec"
    BF_ACSC                     "ACsc"
    BF_SINH                     "SinH"
    BF_COSH                     "CosH"
    BF_TANH                     "TanH"
    BF_ASINH                    "ASinH"
    BF_ACOSH                    "ACosH"
    BF_ATANH                    "ATanH"
    BF_ABS                      "Abs"
    BF_SQRT                     "Sqrt"
    BF_INT                      "Int"
    BF_FRAC                     "Frac"
    BF_SQR                      "Sqr"
    BF_CUBE                     "Cube"
    BF_ROUND                    "Round"
    BF_FACT                     "Fact"
    BF_POW                      "Pow"
    BF_INC                      "Inc"
    BF_DEC                      "Dec"
    BF_SUM                      "Sum"
    BF_MAX                      "Max"
    BF_MIN                      "Min"
    BF_AVG                      "Avg"
    BF_PROD                     "Prod"
    BF_POLY                     "Poly"
    EQ                          "=="
    NE                          "!="
    LE                          "<="
    GE                          ">="
    AND                         "&&"
    OR                          "||"
    PP                          "++"
    NN                          "--"
    PA                          "+="
    NA                          "-="
    MA                          "*="
    DA                          "/="
    VOID_ARRAY_INIT             "void_ArrayInit"
    VOID_ARRAY_INIT_IF_EMPTY    "ArrayInitIfEmpty"
    ARRAY_SIZE                  "ArraySize"
    VOID_ARRAY_CLEAR            "void_ArrayClear"
    VOID_ARRAY_PUSH_BACK        "void_ArrayPushBack"
    VOID_ARRAY_PUSH_FRONT       "void_ArrayPushFront"
    VOID_ARRAY_POP_BACK         "void_ArrayPopBack"
    VOID_ARRAY_POP_FRONT        "void_ArrayPopFront"
    VOID_ARRAY_AT               "void_ArrayAt"
    ARRAY_AT                    "ArrayAt"
    ARRAY_FRONT                 "ArrayFront"
    ARRAY_BACK                  "ArrayBack"
    VOID_ARRAY_INSERT           "void_ArrayInsert"
    VOID_ARRAY_ERASE            "void_ArrayErase"
    VOID_ARRAY_ERASE_VALUE      "void_ArrayEraseValue"
    VOID_ARRAY_RESIZE           "void_ArrayResize"
    VOID_ARRAY_SORT             "void_ArraySort"
    VOID_ARRAY_UNIQUE           "void_ArrayUnique"
    VOID_ARRAY_REVERSE          "void_ArrayReverse"
    ARRAY_PROD                  "ArrayProd"
    ARRAY_AVG                   "ArrayAvg"
    ARRAY_MIN                   "ArrayMin"
    ARRAY_MAX                   "ArrayMax"
    ARRAY_SUM                   "ArraySum"
    ARRAY_POLY                  "ArrayPoly"
;

%type <std::shared_ptr<TActionNode>>
    options
    option
    function_declarations
    function_declaration_arguments
    function_declaration
    variables
    variable
    program_expression
    if_expression
    if_block_expression
    loop_expression
    block_expression
    one_block_expression
    identifier_operation
    math_expression
    math_and_or
    math_compare
    plus_minus
    multiplication_division
    variable_function
    function_argument
    function_arguments
    build_in_function
    result_array_functions
    void_array_function
    invoke_user_functions
    TRUE_CONST
    FALSE_CONST
    BF_ERRORVALUE
    BF_ISERRORVALUE
;


//
// Грамматика парсера
//
%%
//-----------------------------------------------------------------------
program : options function_declarations variables program_expression    {
                                                                            if ($1) root.AddNode($1);
                                                                            if ($2) root.AddNode($2);
                                                                            if ($3) root.AddNode($3);
                                                                            root.AddNode($4);
                                                                        }
        ;
//-----------------------------------------------------------------------
//
// Описание набора настроек
//
options : %empty                {}
        | option ';' options    {
                                    if ($3 == nullptr)
                                    {
                                        $$ = std::make_shared<TActionNode>(TActionType::Options);
                                    }
                                    else
                                    {
                                        $$ = $3;
                                    }
                                    $$->AddNode($1, false);
                                }
        ;
//-----------------------------------------------------------------------
//
// Описание одной настройки
//
option  : '#' OPT_ERRORVALUE NUMBER     {
                                            $$ = std::make_shared<TActionNode>(TActionType::OptErrorValue);
                                            $$->AddNode(std::make_shared<TActionNode>($3));
                                        }
        | '#' OPT_ERRORVALUE '-' NUMBER {
                                            $$ = std::make_shared<TActionNode>(TActionType::OptErrorValue);
                                            $$->AddNode(std::make_shared<TActionNode>($4 * -1));
                                        }
        | '#' OPT_LOOPLIMIT NUMBER      {
                                            $$ = std::make_shared<TActionNode>(TActionType::OptLoopLimit);
                                            $$->AddNode(std::make_shared<TActionNode>($3));
                                        }
       ;
//-----------------------------------------------------------------------
//
// Описание набора функций
//
function_declarations   : %empty                                        {}
                        | function_declaration function_declarations    {
                                                                            if ($2 == nullptr)
                                                                            {
                                                                                $$ = std::make_shared<TActionNode>(TActionType::Functions);
                                                                            }
                                                                            else
                                                                            {
                                                                                $$ = $2;
                                                                            }
                                                                            $$->AddNode($1, false);
                                                                        }
//-----------------------------------------------------------------------
//
// Аргументы функции при объявлении
//
function_declaration_arguments  : function_declaration_arguments ',' IDENTIFIER {
                                                                                    if ($1 == nullptr)
                                                                                    {
                                                                                        $$ = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        $$ = $1;
                                                                                    }
                                                                                    $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $3));
                                                                                }
                                | IDENTIFIER                                    {
                                                                                    $$ = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                                    $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                                                }
                                ;
//-----------------------------------------------------------------------
//
// Описание функции определённой пользователем
//
function_declaration    : FUNCTION IDENTIFIER '(' ')' '{' variables program_expression '}'                                  {
                                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Function, $2);
                                                                                                                                if ($6) $$->AddNode($6);
                                                                                                                                $$->AddNode($7);
                                                                                                                            }
                        | FUNCTION IDENTIFIER '(' function_declaration_arguments ')' '{' variables program_expression '}'   {
                                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Function, $2);
                                                                                                                                if ($4) $$->AddNode($4);
                                                                                                                                if ($7) $$->AddNode($7);
                                                                                                                                $$->AddNode($8);
                                                                                                                            }
                        ;
//-----------------------------------------------------------------------
//
// Описание набора переменных
//
variables   : %empty                    {}
            | variable ';' variables    {
                                            if ($3 == nullptr)
                                            {
                                                $$ = std::make_shared<TActionNode>(TActionType::Variables);
                                            }
                                            else
                                            {
                                                $$ = $3;
                                            }
                                            $$->AddNode($1, false);
                                        }
            ;
//-----------------------------------------------------------------------
//
// Описание одной переменной
//
variable    : VAR IDENTIFIER                        {
                                                        $$ = std::make_shared<TActionNode>(TActionType::Var);
                                                        $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $2));
                                                    }
            | VAR IDENTIFIER '=' math_expression    {
                                                        $$ = std::make_shared<TActionNode>(TActionType::Var);
                                                        $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $2));
                                                        $$->AddNode($4);
                                                    }
            ;
//-----------------------------------------------------------------------
//
// Набор операций в основной программе
//
program_expression  : math_expression ';'                           {
                                                                        $$ = std::make_shared<TActionNode>(TActionType::Main);
                                                                        $$->AddNode($1, false);
                                                                    }
                    | identifier_operation ';' program_expression   {
                                                                        if ($3 == nullptr)
                                                                        {
                                                                            $$ = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            $$ = $3;
                                                                        }
                                                                        $$->AddNode($1, false);
                                                                    }
                    | void_array_function ';' program_expression    {
                                                                        if ($3 == nullptr)
                                                                        {
                                                                            $$ = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            $$ = $3;
                                                                        }
                                                                        $$->AddNode($1, false);
                                                                    }
                    | if_expression program_expression              {
                                                                        if ($2 == nullptr)
                                                                        {
                                                                            $$ = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            $$ = $2;
                                                                        }
                                                                        $$->AddNode($1, false);
                                                                    }
                    | loop_expression program_expression            {
                                                                        if ($2 == nullptr)
                                                                        {
                                                                            $$ = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            $$ = $2;
                                                                        }
                                                                        $$->AddNode($1, false);
                                                                    }
                    ;
//-----------------------------------------------------------------------
//
// Ветвление
//
if_expression   : IF '(' math_expression ')' if_block_expression                            {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::If);
                                                                                                $$->AddNode($3);
                                                                                                $5->Set(TActionType::TrueBlock);
                                                                                                $$->AddNode($5);
                                                                                            }
                | IF '(' math_expression ')' if_block_expression ELSE if_block_expression   {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::If);
                                                                                                $$->AddNode($3);
                                                                                                $5->Set(TActionType::TrueBlock);
                                                                                                $$->AddNode($5);
                                                                                                $7->Set(TActionType::FalseBlock);
                                                                                                $$->AddNode($7);
                                                                                            }
                | IF '(' math_expression ')' if_block_expression ELSE if_expression         {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::If);
                                                                                                $$->AddNode($3);
                                                                                                $5->Set(TActionType::TrueBlock);
                                                                                                $$->AddNode($5);
                                                                                                $$->AddNode($7);
                                                                                            }
                ;
//-----------------------------------------------------------------------
//
// Блок для ветвления IF
//
if_block_expression : '{' block_expression '}'  { $$ = $2; }
                    | one_block_expression      { $$ = $1; }
                    ;
//-----------------------------------------------------------------------
//
// Циклы
//
loop_expression : WHILE '(' math_expression ')' '{' block_expression '}'                                                    {
                                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::While);
                                                                                                                                $$->AddNode($3);
                                                                                                                                $$->AddNode($6);
                                                                                                                            }
                | DO_WHILE '{' block_expression '}' WHILE '(' math_expression ')'                                           {
                                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::DoWhile);
                                                                                                                                $$->AddNode($3);
                                                                                                                                $$->AddNode($7);
                                                                                                                            }
                | FOR '(' identifier_operation ';' math_expression ';' identifier_operation ')' '{' block_expression '}'    {
                                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::For);
                                                                                                                                $$->AddNode($3);
                                                                                                                                $$->AddNode($5);
                                                                                                                                $$->AddNode($10);
                                                                                                                                $$->AddNode($7);
                                                                                                                            }
                | FOR '(' ';' math_expression ';' identifier_operation ')' '{' block_expression '}'                         {
                                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::For);
                                                                                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Empty));
                                                                                                                                $$->AddNode($4);
                                                                                                                                $$->AddNode($9);
                                                                                                                                $$->AddNode($6);
                                                                                                                            }
                | FOR '(' ';' math_expression ';' ')' '{' block_expression '}'                                              {
                                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::For);
                                                                                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Empty));
                                                                                                                                $$->AddNode($4);
                                                                                                                                $$->AddNode($8);
                                                                                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Empty));
                                                                                                                            }
                ;
//-----------------------------------------------------------------------
//
// Набор операций в блоке
//
block_expression    : %empty                                    {
                                                                    if ($$ == nullptr)
                                                                    {
                                                                        $$ = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                }
                    | one_block_expression block_expression     {
                                                                    if ($2 == nullptr)
                                                                    {
                                                                        $$ = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                    else
                                                                    {
                                                                        $$ = $2;
                                                                    }
                                                                    $$->AddNodes($1->Nodes, false);
                                                                }
                    | if_expression block_expression            {
                                                                    if ($2 == nullptr)
                                                                    {
                                                                        $$ = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                    else
                                                                    {
                                                                        $$ = $2;
                                                                    }
                                                                    $$->AddNode($1, false);
                                                                }
                    | loop_expression block_expression          {
                                                                    if ($2 == nullptr)
                                                                    {
                                                                        $$ = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                    else
                                                                    {
                                                                        $$ = $2;
                                                                    }
                                                                    $$->AddNode($1, false);
                                                                }
                    ;
//-----------------------------------------------------------------------
//
// Одна операция в блоке
//
one_block_expression    :   BREAK ';'               {
                                                        $$ = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                        $$->AddNode(std::make_shared<TActionNode>(TActionType::Break), false);
                                                    }
                        | identifier_operation ';'  {
                                                        $$ = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                        $$->AddNode($1, false);
                                                    }
                        | void_array_function ';'   {
                                                        $$ = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                        $$->AddNode($1, false);
                                                    }
                        ;
//-----------------------------------------------------------------------
//
// Операции над идентификаторами
//
identifier_operation    : IDENTIFIER '=' math_expression    {
                                                                $$ = std::make_shared<TActionNode>(TActionType::Assignment);
                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                                $$->AddNode($3);
                                                            }
                        | IDENTIFIER PP                     {
                                                                $$ = std::make_shared<TActionNode>(TActionType::PlusPlus);
                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                            }
                        | IDENTIFIER NN                     {
                                                                $$ = std::make_shared<TActionNode>(TActionType::MinusMinus);
                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                            }
                        | IDENTIFIER PA math_expression     {
                                                                $$ = std::make_shared<TActionNode>(TActionType::PlusAssignment);
                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                                $$->AddNode($3);
                                                            }
                        | IDENTIFIER NA math_expression     {
                                                                $$ = std::make_shared<TActionNode>(TActionType::MinusAssignment);
                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                                $$->AddNode($3);
                                                            }
                        | IDENTIFIER MA math_expression     {
                                                                $$ = std::make_shared<TActionNode>(TActionType::MultAssignment);
                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                                $$->AddNode($3);
                                                            }
                        | IDENTIFIER DA math_expression     {
                                                                $$ = std::make_shared<TActionNode>(TActionType::DivisionAssignment);
                                                                $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $1));
                                                                $$->AddNode($3);
                                                            }
                        ;
//-----------------------------------------------------------------------
//
// Базовое математическое выражение
//
math_expression : math_and_or   { $$ = $1; }
                ;
//-----------------------------------------------------------------------
//
// Логические И ИЛИ
//
math_and_or : math_compare AND math_and_or  {
                                                $$ = std::make_shared<TActionNode>(TActionType::And);
                                                $$->AddNode($1);
                                                $$->AddNode($3);
                                            }
            | math_compare OR math_and_or   {
                                                $$ = std::make_shared<TActionNode>(TActionType::Or);
                                                $$->AddNode($1);
                                                $$->AddNode($3);
                                            }
            | math_compare                  {   $$ = $1; }
            ;
//-----------------------------------------------------------------------
//
// Операции сравнения
//
math_compare    : plus_minus '>' math_compare   {
                                                    $$ = std::make_shared<TActionNode>(TActionType::Bigger);
                                                    $$->AddNode($1);
                                                    $$->AddNode($3);
                                                }
                | plus_minus '<' math_compare   {
                                                    $$ = std::make_shared<TActionNode>(TActionType::Smaller);
                                                    $$->AddNode($1);
                                                    $$->AddNode($3);
                                                }
                | plus_minus EQ math_compare    {
                                                    $$ = std::make_shared<TActionNode>(TActionType::EqualEqual);
                                                    $$->AddNode($1);
                                                    $$->AddNode($3);
                                                }
                | plus_minus NE math_compare    {
                                                    $$ = std::make_shared<TActionNode>(TActionType::NotEqual);
                                                    $$->AddNode($1);
                                                    $$->AddNode($3);
                                                }
                | plus_minus LE math_compare    {
                                                    $$ = std::make_shared<TActionNode>(TActionType::LessOrEqual);
                                                    $$->AddNode($1);
                                                    $$->AddNode($3);
                                                }
                | plus_minus GE math_compare    {
                                                    $$ = std::make_shared<TActionNode>(TActionType::GreatOrEqual);
                                                    $$->AddNode($1);
                                                    $$->AddNode($3);
                                                }
                | plus_minus                    {   $$ = $1; }
                ;
//-----------------------------------------------------------------------
//
// Сумма, разность
//
plus_minus  : multiplication_division '+' plus_minus    {
                                                            $$ = std::make_shared<TActionNode>(TActionType::Plus);
                                                            $$->AddNode($1);
                                                            $$->AddNode($3);
                                                        }
            | multiplication_division '-' plus_minus    {
                                                            $$ = std::make_shared<TActionNode>(TActionType::Minus);
                                                            $$->AddNode($1);
                                                            $$->AddNode($3);
                                                        }
            | multiplication_division                   {   $$ = $1; }
            ;
//-----------------------------------------------------------------------
//
// Умножение, деление
//
multiplication_division : variable_function '*' multiplication_division {
                                                                            $$ = std::make_shared<TActionNode>(TActionType::Multiplication);
                                                                            $$->AddNode($1);
                                                                            $$->AddNode($3);
                                                                        }
                        | variable_function '/' multiplication_division {
                                                                            $$ = std::make_shared<TActionNode>(TActionType::Division);
                                                                            $$->AddNode($1);
                                                                            $$->AddNode($3);
                                                                        }
                        | variable_function                             {   $$ = $1; }
                        ;
//-----------------------------------------------------------------------
//
// Скобки, встроенные функции, константы, идентификаторы
//
variable_function   : '(' math_expression ')'   { $$ = $2; }
                    | build_in_function         { $$ = $1; }
                    | result_array_functions    { $$ = $1; }
                    | invoke_user_functions     { $$ = $1; }
                    | '-' NUMBER                { $$ = std::make_shared<TActionNode>($2 * -1); }
                    | NUMBER                    { $$ = std::make_shared<TActionNode>($1); }
                    | '-' IDENTIFIER            {
                                                    $$ = std::make_shared<TActionNode>(TActionType::Multiplication);
                                                    $$->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, $2));
                                                    $$->AddNode(std::make_shared<TActionNode>(double(-1)));
                                                }
                    | IDENTIFIER                { $$ = std::make_shared<TActionNode>(TActionType::Identifier, $1); }
                    | TRUE_CONST                { $$ = std::make_shared<TActionNode>(TActionType::True); }
                    | FALSE_CONST               { $$ = std::make_shared<TActionNode>(TActionType::False); }
                    ;
//-----------------------------------------------------------------------
//
// Один аргумент для функции
//
function_argument   : math_expression   { $$ = $1; }
                    ;
//-----------------------------------------------------------------------
//
// Набор входных аргументов для функций - несколько аргументов
//
function_arguments  : function_arguments ';' math_expression    {
                                                                    if ($1 == nullptr)
                                                                    {
                                                                        $$ = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                    }
                                                                    else
                                                                    {
                                                                        $$ = $1;
                                                                    }
                                                                    $$->AddNode($3);
                                                                }
                    | math_expression                           {
                                                                    $$ = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                    $$->AddNode($1);
                                                                }
                    ;
//-----------------------------------------------------------------------
//
// Встроенные функции
//
build_in_function   : BF_PI '(' ')'                                                         {   $$ = std::make_shared<TActionNode>(TActionType::Pi); }
                    | BF_ERRORVALUE '(' ')'                                                 {   $$ = std::make_shared<TActionNode>(TActionType::ErrorValue); }
                    | BF_ISERRORVALUE '(' function_argument ')'                             {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::IsErrorValue);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_IFERRORVALUEDEF '(' function_argument ';' function_argument ')'    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::IfErrValueDef);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | BF_LN    '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Ln);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_LG    '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Lg);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_SIN   '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Sin);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_COS   '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Cos);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_TAN   '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Tan);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_COTAN '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::CoTan);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_SEC '(' function_argument ')'                                      {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Sec);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_CSC '(' function_argument ')'                                      {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Csc);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ASIN  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ASin);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ACOS  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ACos);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ATAN  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ATan);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ACOTAN  '(' function_argument ')'                                  {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ACoTan);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ASEC  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ASec);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ACSC  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ACsc);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_SINH  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::SinH);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_COSH  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::CosH);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_TANH  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::TanH);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ASINH '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ASinH);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ACOSH '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ACosH);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ATANH '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ATanH);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ABS   '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Abs);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_SQRT  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Sqrt);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_INT   '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Int);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_FRAC  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Frac);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_SQR   '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Sqr);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_CUBE  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Cube);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_ROUND '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Round);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_FACT  '(' function_argument ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Fact);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | BF_POW   '(' function_argument ';' function_argument ')'              {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Pow);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | BF_INC   '(' function_argument ';' function_argument ')'              {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Inc);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | BF_DEC   '(' function_argument ';' function_argument ')'              {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Dec);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | BF_SUM   '(' function_arguments ')'                                   {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Sum);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | BF_MAX   '(' function_arguments ')'                                   {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Max);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | BF_MIN   '(' function_arguments ')'                                   {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Min);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | BF_AVG   '(' function_arguments ')'                                   {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Avg);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | BF_PROD  '(' function_arguments ')'                                   {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Prod);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | BF_POLY '(' function_arguments ')'                                    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Poly);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    ;
//-----------------------------------------------------------------------
//
// Функции для работы с глобальным массивом результат которых может использоваться
//
result_array_functions  : ARRAY_SIZE '(' ')'                                                                {   $$ = std::make_shared<TActionNode>(TActionType::ArraySize); }
                        | ARRAY_AT '(' function_argument ')'                                                {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArrayAt);
                                                                                                                $$->AddNode($3);
                                                                                                            }
                        | ARRAY_FRONT '(' ')'                                                               {   $$ = std::make_shared<TActionNode>(TActionType::ArrayFront); }
                        | ARRAY_BACK '(' ')'                                                                {   $$ = std::make_shared<TActionNode>(TActionType::ArrayBack); }
                        | ARRAY_PROD '(' ')'                                                                {   $$ = std::make_shared<TActionNode>(TActionType::ArrayProd); }
                        | ARRAY_PROD '(' function_argument ';' function_argument ')'                        {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArrayProd);
                                                                                                                $$->AddNode($3);
                                                                                                                $$->AddNode($5);
                                                                                                            }
                        | ARRAY_AVG '(' ')'                                                                 {   $$ = std::make_shared<TActionNode>(TActionType::ArrayAvg); }
                        | ARRAY_AVG '(' function_argument ';' function_argument ')'                         {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArrayAvg);
                                                                                                                $$->AddNode($3);
                                                                                                                $$->AddNode($5);
                                                                                                            }
                        | ARRAY_MIN '(' ')'                                                                 {   $$ = std::make_shared<TActionNode>(TActionType::ArrayMin); }
                        | ARRAY_MIN '(' function_argument ';' function_argument ')'                         {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArrayMin);
                                                                                                                $$->AddNode($3);
                                                                                                                $$->AddNode($5);
                                                                                                            }
                        | ARRAY_MAX '(' ')'                                                                 {   $$ = std::make_shared<TActionNode>(TActionType::ArrayMax); }
                        | ARRAY_MAX '(' function_argument ';' function_argument ')'                         {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArrayMax);
                                                                                                                $$->AddNode($3);
                                                                                                                $$->AddNode($5);
                                                                                                            }
                        | ARRAY_SUM '(' ')'                                                                 {   $$ = std::make_shared<TActionNode>(TActionType::ArraySum); }
                        | ARRAY_SUM '(' function_argument ';' function_argument ')'                         {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArraySum);
                                                                                                                $$->AddNode($3);
                                                                                                                $$->AddNode($5);
                                                                                                            }
                        | ARRAY_POLY '(' function_argument ')'                                              {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArrayPoly);
                                                                                                                $$->AddNode($3);
                                                                                                            }
                        | ARRAY_POLY '(' function_argument ';' function_argument ';' function_argument ')'  {
                                                                                                                $$ = std::make_shared<TActionNode>(TActionType::ArrayPoly);
                                                                                                                $$->AddNode($3);
                                                                                                                $$->AddNode($5);
                                                                                                                $$->AddNode($7);
                                                                                                            }
                        ;
//-----------------------------------------------------------------------
//
// Функции для работы с глобальным массивом результат которых может не использоваться
//
void_array_function : VOID_ARRAY_INIT '(' function_arguments ')'                            {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayInit);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | VOID_ARRAY_INIT_IF_EMPTY '(' function_arguments ')'                   {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayInitIfEmpty);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | VOID_ARRAY_CLEAR '(' ')'                                              {   $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayClear); }
                    | VOID_ARRAY_PUSH_BACK '(' function_arguments ')'                       {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayPushBack);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | VOID_ARRAY_PUSH_FRONT '(' function_arguments ')'                      {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayPushFront);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | VOID_ARRAY_POP_BACK '(' ')'                                           {   $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayPopBack); }
                    | VOID_ARRAY_POP_FRONT '(' ')'                                          {   $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayPopFront); }
                    | VOID_ARRAY_AT '(' function_argument ';' function_argument ')'         {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayAt);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | VOID_ARRAY_INSERT '(' function_argument ';' function_arguments ')'    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayInsert);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNodes($5->Nodes);
                                                                                            }
                    | VOID_ARRAY_ERASE '(' function_argument ')'                            {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayErase);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | VOID_ARRAY_ERASE '(' function_argument ';' function_argument ')'      {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayErase);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | VOID_ARRAY_ERASE_VALUE '(' function_arguments ')'                     {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayEraseValue);
                                                                                                $$->Nodes = std::move($3->Nodes);
                                                                                            }
                    | VOID_ARRAY_RESIZE '(' function_argument ')'                           {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayResize);
                                                                                                $$->AddNode($3);
                                                                                            }
                    | VOID_ARRAY_RESIZE '(' function_argument ';' function_argument ')'     {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayResize);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | VOID_ARRAY_SORT '(' ')'                                               {   $$ = std::make_shared<TActionNode>(TActionType::Void_ArraySort); }
                    | VOID_ARRAY_SORT '(' function_argument ';' function_argument ')'       {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArraySort);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | VOID_ARRAY_REVERSE '(' ')'                                            {   $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayReverse); }
                    | VOID_ARRAY_REVERSE '(' function_argument ';' function_argument ')'    {
                                                                                                $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayReverse);
                                                                                                $$->AddNode($3);
                                                                                                $$->AddNode($5);
                                                                                            }
                    | VOID_ARRAY_UNIQUE '(' ')'                                             {   $$ = std::make_shared<TActionNode>(TActionType::Void_ArrayUnique); }
                    ;
//-----------------------------------------------------------------------
//
// Вызов функции определённой пользователем
//
invoke_user_functions   : IDENTIFIER '('')'                     {   $$ = std::make_shared<TActionNode>(TActionType::InvokeFunction, $1); }
                        | IDENTIFIER '(' function_arguments ')' {
                                                                    $$ = std::make_shared<TActionNode>(TActionType::InvokeFunction, $1);
                                                                    $$->Nodes = std::move($3->Nodes);
                                                                }
                        ;
%%


//
// Функция обработки ошибок
//
void CalcPlusPlus::TParser::error(const location& loc, const std::string& msg)
{
    if (std::string matcher_line(lexer.matcher().line()); matcher_line.empty())
    {
        Framework::String::TStringFormater::VoidFormat(error_msg, "Ошибка ({0}:{1}): {2}.",
                        loc.begin.line,
                        loc.begin.column,
                        msg);
    }
    else
    {
        std::string match_error("");

        for (int i = 0; i < loc.begin.column; ++i) match_error += " ";

        for (int i = loc.begin.column; i <= loc.end.column; ++i) match_error += "~";

        Framework::String::TStringFormater::VoidFormat(error_msg, "Ошибка ({0}:{1}): {2}.\n\t{3}\n\t{4}",
                        loc.begin.line,
                        loc.begin.column,
                        msg,
                        matcher_line,
                        match_error);
    }

    VOID_AUTO_ENCODING(std::string, error_msg);
}