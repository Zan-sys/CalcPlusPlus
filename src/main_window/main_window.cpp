#include "main_window.hpp"
// ---------------------------------------------------------------------------
#include <fw_base.hpp>
// ---------------------------------------------------------------------------
using namespace std;
using namespace Framework::String;
using namespace Framework::StdExtension;
// ---------------------------------------------------------------------------
//
// Конструктор
//
TMainWindow::TMainWindow() : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG), interpreter(nullptr) {}
// ---------------------------------------------------------------------------
//
// Формирование строки для Sciter
//
sciter::string TMainWindow::MakeSciterString(std::string str)
{
    T_VOID_AUTO_ENCODING(str);

    aux::a2w value(str);

    return sciter::string(value.c_str(), value.length());
}
// ---------------------------------------------------------------------------
//
// Преобразование строки Sciter в стандартную
//
std::string TMainWindow::SciterStringToStd(const sciter::string& str)
{
    aux::w2a temp(str);

    string result = Framework::String::TStringConverter::ToString(temp.c_str(), temp.length());

    T_VOID_AUTO_ENCODING(result);

    return result;
}
// ---------------------------------------------------------------------------
//
// Инициализация интерпретатора
//
sciter::value TMainWindow::InitInterpreter(const sciter::string& math_code)
{
    string error;

    CalcPlusPlus::TIncludeList include_list;

    sciter::value sciter_map = sciter::value::make_map();

    string _math_code = TStringEncoding::ToUtf8(SciterStringToStd(math_code));

    interpreter = make_unique<CalcPlusPlus::TInterpreter>();

    sciter_map.set_item(MakeSciterString("result"), interpreter->SetExpression(_math_code, include_list, external_identifiers, error));
    sciter_map.set_item(MakeSciterString("error"), MakeSciterString(error));

    return sciter_map;
}
// ---------------------------------------------------------------------------
//
// Формирование дерева разбора
//
sciter::value TMainWindow::BuildParseTree(std::shared_ptr<CalcPlusPlus::TActionNode> node)
{
    string caption;

    auto value = sciter::value::make_map();

    switch (node->Type)
    {
        //
        // Идентификатор
        //
    case CalcPlusPlus::TActionType::Identifier:
        if (node->ExternalID)
        {
            TStringFormater::VoidFormat(caption, "External Identifier: {0}. Address: {1}", node->Name, TStringConverter::ToHexString(reinterpret_cast<std::size_t>(node->ExternalID.get())));
        }
        else
        {
            TStringFormater::VoidFormat(caption, "Identifier: {0}. Stack index: {1}", node->Name, node->Index);
        }
        break;
        //
        // Число
        //
    case CalcPlusPlus::TActionType::Number: TStringFormater::VoidFormat(caption, "Number: {0}", TStringConverter::ToString(node->Number, std::locale(), std::numeric_limits<double>::max_digits10)); break;
        //
        // Функция
        //
    case CalcPlusPlus::TActionType::Function: TStringFormater::VoidFormat(caption, "Function: {0}. Address: {1}", node->Name, TStringConverter::ToHexString(reinterpret_cast<std::size_t>(node.get()))); break;
        //
        // Вызов функции
        //
    case CalcPlusPlus::TActionType::InvokeFunction: TStringFormater::VoidFormat(caption, "InvokeFunction: {0}. Address: {1}", node->Name, TStringConverter::ToHexString(reinterpret_cast<std::size_t>(node->Invoke.get()))); break;
        //
        // Остальные узлы
        //
    default: caption = node->Name; break;
    }
    //
    // Устанавливаем данные узла
    //
    value.set_item(MakeSciterString("caption"), MakeSciterString(caption));
    //
    // Добавляем дочерние узлы
    //
    if (!node->Nodes.empty())
    {
        std::vector<sciter::value> items;
        //
        // Добавляем внешние идентификаторы
        //
        if (node->Is(CalcPlusPlus::TActionType::Program) && !external_identifiers.empty())
        {
            sciter::value ext_ids = sciter::value::make_map();
            ext_ids.set_item(MakeSciterString("caption"), MakeSciterString("External_identifiers"));

            vector<sciter::value> ext_items;

            for (auto item : external_identifiers)
            {
                auto ext_id = sciter::value::make_map();
                string value = TStringFormater::Format("External Identifier: {0}. Address: {1}", item.first, TStringConverter::ToHexString(reinterpret_cast<std::size_t>(item.second.get())));
                ext_id.set_item(MakeSciterString("caption"), MakeSciterString(value));
                ext_items.push_back(ext_id);
            }

            ext_ids.set_item(MakeSciterString("options"), ext_items);
            items.push_back(ext_ids);
        }
        //
        // Добавляем дочерние узлы
        //
        for (auto _node : node->Nodes)
        {
            items.push_back(BuildParseTree(_node));
        }

        value.set_item(MakeSciterString("options"), items);
    }

    return value;
}
// ---------------------------------------------------------------------------
//
// Метод возвращает объект с деревом разбора
//
sciter::value TMainWindow::GetParseTreeTree()
{
    sciter::value result;

    if (interpreter)
    {
        if (shared_ptr<CalcPlusPlus::TActionNode> root = interpreter->GetParseTree(); root)
        {
            result = BuildParseTree(root);
        }
    }

    return result;
}
// ---------------------------------------------------------------------------
//
// Метод возвращает данные из глобального массива интерпретатора
//
sciter::value TMainWindow::GetGlobalArray()
{
    vector<double> values;

    if (interpreter)
    {
        interpreter->GetGlobalArray(values);
    }

    return sciter::value(values);
}
// ---------------------------------------------------------------------------
//
// Метод возвращает список внешних переменных
//
sciter::value TMainWindow::GetExternalId()
{
    vector<sciter::value> items;

    for (auto& value : external_identifiers)
    {
        auto s_value = sciter::value::make_map();

        s_value.set_item(MakeSciterString("caption"), MakeSciterString(value.first));
        s_value.set_item(MakeSciterString("value"), MakeSciterString(TStringConverter::ToString(*(value.second), std::locale(), std::numeric_limits<double>::max_digits10)));

        items.push_back(s_value);
    }

    return items;
}
// ---------------------------------------------------------------------------
//
// Метод инициализирует список внешних переменных
//
void TMainWindow::SetExternalId(const std::vector<sciter::value>& values)
{
    for (auto value : values)
    {
        if (value.is_object())
        {
            string caption = SciterStringToStd(value.get_item(MakeSciterString("caption")).to_string());
            string _value = SciterStringToStd(value.get_item(MakeSciterString("value")).to_string());

            auto it = find_if(begin(external_identifiers), end(external_identifiers), [&caption](auto& item)
            {
                return TStringExtension::Compare(caption, item.first, true);
            });

            if (it != end(external_identifiers))
            {
                *(it->second) = TStringConverter::FromString(_value, numeric_limits<double>::quiet_NaN());
            }
        }
    }
}
// ---------------------------------------------------------------------------
//
// Выполнение математического выражения
//
sciter::value TMainWindow::Run()
{
    sciter::value result;

    if (interpreter && interpreter->GetParseTree())
    {
        double value(numeric_limits<double>::quiet_NaN());

        result = sciter::value::make_map();

        result.set_item(MakeSciterString("result"), interpreter->Run(value));

        result.set_item(MakeSciterString("value"), MakeSciterString(TStringConverter::ToString(value, std::locale(), std::numeric_limits<double>::max_digits10)));
    }

    return result;
}
// ---------------------------------------------------------------------------
