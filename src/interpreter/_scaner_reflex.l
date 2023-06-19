//
// Код будет добавлен в заголовочный файл сканера (hpp)
//
%top{
    #include <project-config.hpp>
    //
    // Подключаем заголовочные файлы парсера
    //
    #include "parser.hpp"
    #include "location.hpp"
    #include "fw_base.hpp"
}

//
// Код будет помещён в начало cpp файла сканера
//
%{
    //
    // Отключаем предупреждение для WINDOWS
    //
#ifdef WINDOWS
    #pragma warning(disable:4102)
#endif
%}

//
// Опции сканера
//
// Игнорируем пробелы в регулярных выражениях (для удобства)
%option freespace
// Оптимизация сканера (таблица состояний помещается в код сканера)
%option fast
// Поддержка юникода
%option unicode
// Пространство имён сканера (такое же как у парсера)
%option namespace=CalcPlusPlus
// Имя класса сканера
%option lexer=TScanner
// Имя файла с кодом сканера (cpp)
%option outfile="scanner.cpp"
// Имя заголовочного файла (hpp)
%option header-file="scanner.hpp"
// Обработка исключений
%option exception="CalcPlusPlus::TParser::syntax_error(location(), \"Unknown token.\")"

//
// Опции для совместимости с BISON
//
%option bison-complete
%option bison-locations
%option bison-cc-namespace=CalcPlusPlus
%option bison-cc-parser=TParser


//
// Класс сканера
//
%class{
private:
    //
    // Глубина подключаемых секций кода
    //
    // size_t depth; /* Используется в Сервере ИВК */
    //
    // Список подключаемых секций кода
    //
    // const std::vector<std::pair<std::string, std::string>>& _include_list; /* Используется в Сервере ИВК */
    std::vector<std::shared_ptr<std::string>> _include_list;
    //
    // Поиск ключевого слова
    //
    int keyword(const std::string& identifier)
    {
        static const std::array<std::pair<std::string, int>, 78> keywords =
        {
            std::pair( "true", TParser::token::TOKEN_TRUE_CONST ),
            std::pair( "false", TParser::token::TOKEN_FALSE_CONST ),
            std::pair( "function", TParser::token::TOKEN_FUNCTION ),
            std::pair( "var", TParser::token::TOKEN_VAR ),
            std::pair( "if", TParser::token::TOKEN_IF ),
            std::pair( "else", TParser::token::TOKEN_ELSE ),
            std::pair( "while", TParser::token::TOKEN_WHILE ),
            std::pair( "do", TParser::token::TOKEN_DO_WHILE ),
            std::pair( "for", TParser::token::TOKEN_FOR ),
            std::pair( "break", TParser::token::TOKEN_BREAK ),
            std::pair( "error_value", TParser::token::TOKEN_OPT_ERRORVALUE ),
            std::pair( "loop_limit", TParser::token::TOKEN_OPT_LOOPLIMIT ),
            std::pair( "Pi", TParser::token::TOKEN_BF_PI ),
            std::pair( "ErrorValue", TParser::token::TOKEN_BF_ERRORVALUE ),
            std::pair( "IsErrorValue", TParser::token::TOKEN_BF_ISERRORVALUE ),
            std::pair( "IfErrorValueDef", TParser::token::TOKEN_BF_IFERRORVALUEDEF ),
            std::pair( "Ln", TParser::token::TOKEN_BF_LN ),
            std::pair( "Lg", TParser::token::TOKEN_BF_LG ),
            std::pair( "Sin", TParser::token::TOKEN_BF_SIN ),
            std::pair( "Cos", TParser::token::TOKEN_BF_COS ),
            std::pair( "Tan", TParser::token::TOKEN_BF_TAN ),
            std::pair( "CoTan", TParser::token::TOKEN_BF_COTAN ),
            std::pair( "Sec", TParser::token::TOKEN_BF_SEC ),
            std::pair( "Csc", TParser::token::TOKEN_BF_CSC ),
            std::pair( "ASin", TParser::token::TOKEN_BF_ASIN ),
            std::pair( "ACos", TParser::token::TOKEN_BF_ACOS ),
            std::pair( "ATan", TParser::token::TOKEN_BF_ATAN ),
            std::pair( "ACoTan", TParser::token::TOKEN_BF_ACOTAN ),
            std::pair( "ASec", TParser::token::TOKEN_BF_ASEC ),
            std::pair( "ACsc", TParser::token::TOKEN_BF_ACSC ),
            std::pair( "SinH", TParser::token::TOKEN_BF_SINH ),
            std::pair( "CosH", TParser::token::TOKEN_BF_COSH ),
            std::pair( "TanH", TParser::token::TOKEN_BF_TANH ),
            std::pair( "ASinH", TParser::token::TOKEN_BF_ASINH ),
            std::pair( "ACosH", TParser::token::TOKEN_BF_ACOSH ),
            std::pair( "ATanH", TParser::token::TOKEN_BF_ATANH ),
            std::pair( "Abs", TParser::token::TOKEN_BF_ABS ),
            std::pair( "Sqrt", TParser::token::TOKEN_BF_SQRT ),
            std::pair( "Int", TParser::token::TOKEN_BF_INT ),
            std::pair( "Frac", TParser::token::TOKEN_BF_FRAC ),
            std::pair( "Sqr", TParser::token::TOKEN_BF_SQR ),
            std::pair( "Cube", TParser::token::TOKEN_BF_CUBE ),
            std::pair( "Round", TParser::token::TOKEN_BF_ROUND ),
            std::pair( "Fact", TParser::token::TOKEN_BF_FACT ),
            std::pair( "Pow", TParser::token::TOKEN_BF_POW ),
            std::pair( "Inc", TParser::token::TOKEN_BF_INC ),
            std::pair( "Dec", TParser::token::TOKEN_BF_DEC ),
            std::pair( "Sum", TParser::token::TOKEN_BF_SUM ),
            std::pair( "Max", TParser::token::TOKEN_BF_MAX ),
            std::pair( "Min", TParser::token::TOKEN_BF_MIN ),
            std::pair( "Avg", TParser::token::TOKEN_BF_AVG ),
            std::pair( "Prod", TParser::token::TOKEN_BF_PROD ),
            std::pair( "Poly", TParser::token::TOKEN_BF_POLY ),
            std::pair( "void_ArrayInit", TParser::token::TOKEN_VOID_ARRAY_INIT ),
            std::pair( "void_ArrayInitIfEmpty", TParser::token::TOKEN_VOID_ARRAY_INIT_IF_EMPTY ),
            std::pair( "ArraySize", TParser::token::TOKEN_ARRAY_SIZE ),
            std::pair( "void_ArrayClear", TParser::token::TOKEN_VOID_ARRAY_CLEAR ),
            std::pair( "void_ArrayPushBack", TParser::token::TOKEN_VOID_ARRAY_PUSH_BACK ),
            std::pair( "void_ArrayPushFront", TParser::token::TOKEN_VOID_ARRAY_PUSH_FRONT ),
            std::pair( "void_ArrayPopBack", TParser::token::TOKEN_VOID_ARRAY_POP_BACK ),
            std::pair( "void_ArrayPopFront", TParser::token::TOKEN_VOID_ARRAY_POP_FRONT ),
            std::pair( "void_ArrayAt", TParser::token::TOKEN_VOID_ARRAY_AT ),
            std::pair( "ArrayAt", TParser::token::TOKEN_ARRAY_AT ),
            std::pair( "ArrayFront", TParser::token::TOKEN_ARRAY_FRONT ),
            std::pair( "ArrayBack", TParser::token::TOKEN_ARRAY_BACK ),
            std::pair( "void_ArrayInsert", TParser::token::TOKEN_VOID_ARRAY_INSERT ),
            std::pair( "void_ArrayErase", TParser::token::TOKEN_VOID_ARRAY_ERASE ),
            std::pair( "void_ArrayEraseValue", TParser::token::TOKEN_VOID_ARRAY_ERASE_VALUE ),
            std::pair( "void_ArrayResize", TParser::token::TOKEN_VOID_ARRAY_RESIZE ),
            std::pair( "void_ArraySort", TParser::token::TOKEN_VOID_ARRAY_SORT ),
            std::pair( "void_ArrayReverse", TParser::token::TOKEN_VOID_ARRAY_REVERSE ),
            std::pair( "void_ArrayUnique", TParser::token::TOKEN_VOID_ARRAY_UNIQUE ),
            std::pair( "ArrayProd", TParser::token::TOKEN_ARRAY_PROD ),
            std::pair( "ArrayAvg", TParser::token::TOKEN_ARRAY_AVG ),
            std::pair( "ArrayMin", TParser::token::TOKEN_ARRAY_MIN ),
            std::pair( "ArrayMax", TParser::token::TOKEN_ARRAY_MAX ),
            std::pair( "ArraySum", TParser::token::TOKEN_ARRAY_SUM ),
            std::pair( "ArrayPoly", TParser::token::TOKEN_ARRAY_POLY )
        };

        auto _f = std::find_if(std::begin(keywords), std::end(keywords), [&identifier](auto& value) {
            return Framework::String::TStringExtension::Compare(value.first, identifier, true);
        });

        return _f == std::end(keywords) ? 0 : _f->second;
    }
    //
    // Идентификатор или ключевое слово
    //
    TParser::symbol_type KeywordIdentifier()
    {
        std::string identifier = AUTO_ENCODING(decltype(identifier), str());
        int token = keyword(identifier);
        return token ? TParser::symbol_type(token, location()) : TParser::make_IDENTIFIER(identifier, location());
    }
    //
    // Обработка паттерна include
    //
    void make_include()
    {
        if (std::size(_include_list) < 90)
        {
            std::string error;
            std::string include_path(text());
            std::string::size_type pos(include_path.find("\"") + 1);
            std::string::size_type count(include_path.rfind("\"") - pos);

            include_path = include_path.substr(pos, count);

            if (auto [buffer, size] = Framework::FileSystem::TFile<std::string>::ReadAll(include_path, error); buffer && (size > 0))
            {
                std::shared_ptr<std::string> code = std::make_shared<std::string>(static_cast<const char*>(buffer.get()), size);

                *code = Framework::String::TStringEncoding::ToUtf8(*code);

                _include_list.push_back(code);
                push_matcher(new_matcher(*code));
            }
        }
    }
    /* Используется в Сервере ИВК */
    /*
    void make_include()
    {
        if (depth < 100)
        {
            std::string include_name(text());
            std::string::size_type pos(include_name.find("\"") + 1);
            std::string::size_type count(include_name.rfind("\"") - pos);

            include_name = include_name.substr(pos, count);

            auto it = std::find_if(begin(_include_list), end(_include_list), [&](const std::pair<std::string, std::string>& value) {
                return Framework::String::TStringExtension::Compare(value.first, include_name, true);
            });

            if ((it != end(_include_list)) && Framework::String::TStringEncoding::IsUtf8(it->second))
            {
                depth++;
                push_matcher(new_matcher(it->second));
            }
        }
    }
    */
    //
    // Обработка завершения файла
    //
    bool end_of_file()
    {
        if (_include_list.empty())
        {
            return true;
        }
        else
        {
            pop_matcher();
            _include_list.pop_back();
            return false;
        }
    }
    /* Используется в Сервере ИВК */
    /*
    bool end_of_file()
    {
        if (depth == 0)
        {
            return true;
        }
        else
        {
            pop_matcher();
            depth--;
            return false;
        }
    }
    */
}

// %option ctorarg="const std::vector<std::pair<std::string, std::string>>& include_list" /* Используется в Сервере ИВК */
// %option ctorinit="_include_list(include_list), depth(0)" /* Используется в Сервере ИВК */

//
// Регулярные выражения
//
digit                           [0-9]
en                              [a-zA-Z_]
ru_hi                           [АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ]
ru_lo                           [абвгдеёжзийклмнопрстуфхцчшщъыьэюя]
alpha                           ( {en} | {ru_hi} | {ru_lo} )
identifier                      {alpha} ( {alpha} | {digit} )*
exp                             [eE] [-+]? {digit}+
double                          ( {digit}+ ) | ( {digit}+ [.,] {digit}+ {exp}? )
include                         ^\h* "#" \h* [Ii][Nn][Cc][Ll][Uu][Dd][Ee] \h* \".*?\" /h*

//
// Правила сканера
//
%%

[[:space:]]+                    {} // Игнорируем пробельные символы

"//".*\n                        {} // Игнорируем одностроковые комментарии
"/*"(.|\n)*?"*/"                {} // Игнорируем мультистроковые комментарии

{include}                       { make_include(); }
{double}                        { return TParser::make_NUMBER(Framework::String::TStringConverter::FromString(text(), std::numeric_limits<double>::quiet_NaN()) , location()); }
{identifier}                    { return KeywordIdentifier(); }
\[ .+? \]                       {
                                    std::string _identifier = AUTO_ENCODING(decltype(_identifier), str());
                                    _identifier.erase(0, 1).erase(std::size(_identifier) - 1, 1);
                                    return TParser::make_IDENTIFIER(_identifier, location());
                                }

[+\-*/;()><=#{},]               { return TParser::symbol_type(chr(), location()); }

"=="                            { return TParser::symbol_type(TParser::token::TOKEN_EQ, location()); }
"!="                            { return TParser::symbol_type(TParser::token::TOKEN_NE, location()); }
"<="                            { return TParser::symbol_type(TParser::token::TOKEN_LE, location()); }
">="                            { return TParser::symbol_type(TParser::token::TOKEN_GE, location()); }
"&&"                            { return TParser::symbol_type(TParser::token::TOKEN_AND, location()); }
"||"                            { return TParser::symbol_type(TParser::token::TOKEN_OR, location()); }
"++"                            { return TParser::symbol_type(TParser::token::TOKEN_PP, location()); }
"--"                            { return TParser::symbol_type(TParser::token::TOKEN_NN, location()); }
"+="                            { return TParser::symbol_type(TParser::token::TOKEN_PA, location()); }
"-="                            { return TParser::symbol_type(TParser::token::TOKEN_NA, location()); }
"*="                            { return TParser::symbol_type(TParser::token::TOKEN_MA, location()); }
"/="                            { return TParser::symbol_type(TParser::token::TOKEN_DA, location()); }

<<EOF>>                         { if (end_of_file()) return TParser::make_EOF(location()); } // Конец входного потока символов

%%
