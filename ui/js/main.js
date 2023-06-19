//************************************************************************************
// #region ПОДКЛЮЧЕНИЕ МОДУЛЕЙ
//************************************************************************************
import * as sctr from "@sciter";
import * as sys from "@sys";
//************************************************************************************
// #endregion
//************************************************************************************
// #region ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
//************************************************************************************
//
// Формирование элементов дерева разбора
//
function BuildParseTreeNode(node)
{
    if (node.options)
    {
        return <option expanded>
                    <caption>{node.caption}</caption>
                    { node.options.map((_node) => BuildParseTreeNode(_node)) }
               </option>;
    }
    else
    {
        return <option><caption>{node.caption}</caption></option>;
    }
}
//------------------------------------------------------------------------------------
//
// Вывод дерева разбора
//
function InitParseTree(root)
{
    var tree = document.$("#parse-tree-tab>select|tree");

    tree.clear();

    if (root)
    {
        tree.append(BuildParseTreeNode(root));
    }
}
//------------------------------------------------------------------------------------
//
// Вывод данных глобального массива
//
var run_math_global_array = [];
function InitGlobalArray(value)
{
    if (Array.isArray(value))
    {
        run_math_global_array = value;
    }
    else
    {
        run_math_global_array = [];
    }

    var _ul = document.$("#run-math#array-viewer ul");

    document.$("#run-math#array-viewer label").innerText = run_math_global_array.length;

    document.$("#run-math#array-viewer input").value = 0;

    _ul.clear();

    _ul.append(run_math_global_array.map((_value, index) =>
    {
        return <li selectable>{_value}</li>;
    }));
}
//------------------------------------------------------------------------------------
//
// Смещение в глобально массиве
//
function ShiftGlobalArray(begin_index)
{
    var _ul = document.$("#run-math#array-viewer ul");

    _ul.clear();

    _ul.append(run_math_global_array.map((_value, index) =>
    {
        if (index >= begin_index)
        {
            return <li selectable>{_value}</li>;
        }
    }));
}
//------------------------------------------------------------------------------------
//
// Вывод списка внешних переменных
//
function InitExternalId(list)
{
    var tbody = document.$("#run-math table#external-id > tbody");

    tbody.clear();

    if (Array.isArray(list))
    {
        var items = list.map((item) =>
        {
            return <tr><td>{item.caption}</td><td type="text" filter="0123456789+-.,EeЕе">{item.value}</td></tr>
        });

        tbody.append(items);
    }
}
//------------------------------------------------------------------------------------
//
// Функция формирует список внешних переменных
//
function GetExternalId()
{
    var external_id = [];
    var tr = document.$$("#run-math table#external-id > tbody > tr");

    for (var item of tr)
    {
        external_id.push(
        {
            caption: item.firstElementChild.innerText,
            value: item.lastElementChild.innerText
        });
    }

    return external_id;
}
//------------------------------------------------------------------------------------
//
// Вывод результата
//
function SetResult(result, value)
{
    var result_element = document.$("#run-math #result-panel>div:first-of-type");

    result_element.innerText = value;

    if (result == undefined)
    {
        result_element.style.setProperty("color", "black");
    }
    else if (result)
    {
        result_element.style.setProperty("color", "green");
    }
    else
    {
        result_element.style.setProperty("color", "red");
    }
}
//************************************************************************************
// #endregion
//************************************************************************************
// #region ОБРАБОТКА СОБЫТИЙ
//************************************************************************************
//
// Обработка события нажатия на кнопку "Проверить математическое выражение"
//
document.on("click", "#parse-math-exp", (evt, element) =>
{
    if (Window.this.TMainWindow && Window.this.TMainWindow.InitInterpreter)
    {
        var result_panel = document.$("#code-check-result");

        var value = Window.this.TMainWindow.InitInterpreter(document.$("#code-editor").value);

        // result_panel.clear();

        if (value.result)
        {
            result_panel.prepend(<div style="color: green; font-size: 1.4em;">-------------------------------------------------------</div>);
            result_panel.prepend(<div style="color: green; font-size: 1.4em;">{result_panel.childElementCount + 1}. ОШИБОК НЕ НАЙДЕНО</div>);

            InitParseTree(Window.this.TMainWindow.GetParseTreeTree());
            InitGlobalArray(Window.this.TMainWindow.GetGlobalArray());
            InitExternalId(Window.this.TMainWindow.GetExternalId())
        }
        else
        {
            result_panel.prepend(<div style="color: green; font-size: 1.4em;">-------------------------------------------------------</div>);
            result_panel.prepend(<div style="font-size: 1.2em">{value.error}</div>);
            result_panel.prepend(<div style="color: red; font-size: 1.4em;">{result_panel.childElementCount + 1}. ОШИБКА</div>);

            InitParseTree(undefined);
            InitGlobalArray([]);
            InitExternalId(undefined);
        }

        SetResult(undefined, "---");
    }
});
//------------------------------------------------------------------------------------
//
// Обработка события смещения по глобальному массиву
//
document.on("change", "#run-math#array-viewer>input", (evt, element) =>
{
    if (element.value >= 0)
    {
        ShiftGlobalArray(element.value);
    }
});
//------------------------------------------------------------------------------------
//
// Обработка события нажатия на кнопку "ВЫПОЛНИТЬ"
//
document.on("click", "#run-math #result-panel > div:last-of-type", (evt, element) =>
{
    if (Window.this.TMainWindow && Window.this.TMainWindow.SetExternalId)
    {
        //
        // Инициализация внешних переменных
        //
        Window.this.TMainWindow.SetExternalId(GetExternalId());
        //
        // Выполнение математического выражения
        //
        var result = Window.this.TMainWindow.Run();

        if (result)
        {
            //
            // Вывод результата
            //
            SetResult(result.result, result.value);
            //
            // Обновление глобального массива
            //
            InitGlobalArray(Window.this.TMainWindow.GetGlobalArray());
            //
            // Обновление списка внешних переменных
            //
            InitExternalId(Window.this.TMainWindow.GetExternalId())
        }
    }
});
//------------------------------------------------------------------------------------
//
// Обработка события нажатия на кнопку "Загрузка документа из файла"
//
document.on("click", "#load_math-exp", (evt, element) =>
{
    let path = Window.this.selectFile({ filter: "Calc++ file(*.calc++)|*.calc++", mode: "open", path: URL.toPath(__DIR__ ) });

    if (path)
    {
        var buffer = sys.fs.sync.readFile(path);
        document.$("#code-editor").value = sctr.decode(buffer);
    }
});
//------------------------------------------------------------------------------------
//
// Обработка события нажатия на кнопку "Сохранить документ в файл"
//
document.on("click", "#save_math-exp", (evt, element) =>
{
    let path = Window.this.selectFile({ mode:"save", path: URL.toPath(__DIR__) + ".calc++"});

    if (path)
    {
        sys.fs.open(path, "w+", 0o666).then(function(file)
        {
            var buffer = sctr.encode(document.$("#code-editor").value);
            file.write(buffer);
            file.close();
        });
    }
});
//************************************************************************************
// #endregion
//************************************************************************************
// #region ЖИЗНЕННЫЙ ЦИКЛ GUI
//************************************************************************************
//
// СОБЫТИЕ ОБРАБАТЫВАЕТ ЗАГРУЗКУ ГЛАВНОГО ОКНА
//
document.on("ready", () =>
{
    var window_size = [900, 710];
    //
    // Минимальный размер окна
    //
    Window.this.minSize = window_size;
    //
    // Установка размера окна
    //
    var workarea = Window.this.screenBox("workarea", "rect");
    Window.this.move((workarea[2]/2 - window_size[0]/2), (workarea[3]/2 - window_size[1]/2), window_size[0], window_size[1]);
    //
    // Загрузка заголовка окна
    //
    document.$("html>header>window-caption").innerText = "Калькулятор++ ver 1.0.0.1";
    //
    // Инициализация интерфейса
    //
    // document.$("#main-tabs-panel").current = "examples";
});
//************************************************************************************
// #endregion
//************************************************************************************
