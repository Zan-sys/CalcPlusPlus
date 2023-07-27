cmake_minimum_required(VERSION 3.10)
project(CALC++ VERSION 1.0.0.1 LANGUAGES C CXX)

#Определяем операционную систему Windows или Linux
if(WIN32)
    option(WINDOWS "Windows Platform" ON)
    message(STATUS "TARGET SYSTEM IS WINDOWS X86/X64.")
elseif(UNIX)
    option(LINUX "Unix Platform" ON)
    message(STATUS "TARGET SYSTEM IS UNIX OR UNIX-LIKE.")
else()
    message(FATAL_ERROR "TARGET SYSTEM IS NOT WINDOWS OR UNIX-LIKE.")
endif()

#Определяем разрядность сборки
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    option(PROJECT_IMAGE_X64 "Build x64" ON)
    message(STATUS "PROJECT BUILD 64 BIT.")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    option(PROJECT_IMAGE_X86 "Build x86" ON)
    message(STATUS "PROJECT BUILD 32 BIT.")
else()
    message(FATAL_ERROR "FAILED TO DETERMINE PROJECT TYPE 32 BIT OR 64 BIT. CHECK CMAKE_SIZEOF_VOID_P VARIABLE.")
endif()

#Вывод типа приложения GUI
message(STATUS "PROJECT IS GUI APPLICATION.")

#Определяем тип сборки
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    option(PROJECT_BUILD_TYPE_DEBUG "Build type is Debug" ON)
    message(STATUS "PROJECT BUILD TYPE IS DEBUG.")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    option(PROJECT_BUILD_TYPE_RELEASE "Build type is Release" ON)
    message(STATUS "PROJECT BUILD TYPE IS RELEASE.")
else()
    # Проверти настройку CMAKE-TOOLS "cmake.setBuildTypeOnMultiConfig": true или "cmake.configureSettings": { "CMAKE_BUILD_TYPE": "${buildType}"}
    message(FATAL_ERROR "PROJECT BUILD TYPE EMPTY. CHECK CMAKE_BUILD_TYPE VARIABLE.")
endif()

# Установка конфигурационного файла
configure_file("${PROJECT_SOURCE_DIR}/project-config.config"
                "${PROJECT_SOURCE_DIR}/inc/project-config.hpp" @ONLY)


# Список подключаемых библиотек
set(LIB)
# Список директорий с заголовочными файлами
set(INCLUDES ./inc ./lib ./lib/RE-flex/include ./src)
# Директория с исполняемым файлом
set(EXE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# Список ресурсов
set(RC)
# Настройки исполнительного файла
set(EXE_OPTIONS)
# Путь к файлу с точкой входа в программе
set(CPP_MAIN ./src/main.cpp)
# Файл с командами
set(SHELL_FILE_NAME)


if(WIN32) # Для Windows
    add_definitions(-DUNICODE -D_UNICODE -D_CRT_SECURE_NO_WARNINGS -D_WIN32_WINNT=0x0601)
    # Статическое подключение C++ Runtime библиотек только для Release (/MD - динамическое подключение, /MT - статическое подключение)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        message(STATUS "DEFAULT CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
        # Поиск флага /MD в настройках компилятора
        set(MD_EXIST)
        string(FIND ${CMAKE_CXX_FLAGS_RELEASE} "/MD" MD_EXIST)
        # Добавляем флаг /MT в настройки компилятора (обязательно в начало)
        if(MD_EXIST EQUAL -1)
            set(CMAKE_CXX_FLAGS_RELEASE "/MT ${CMAKE_CXX_FLAGS_RELEASE}")
        else() # Заменяем флаг /MD на /MT
            string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
        endif()
        message(STATUS "RESULT CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
    endif()
    # Ресурсы проекта
    set(RC ${PROJECT_SOURCE_DIR}/rc/ico.rc)
    # Файл с командами WINDOWS
    set(SHELL_FILE_NAME shell.bat)
elseif(UNIX) # Для Linux
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 11)
        message(STATUS "EXPERIMENTAL FILESYSTEM - OFF. GCC version: " ${CMAKE_CXX_COMPILER_VERSION})
    else()
        message(STATUS "EXPERIMENTAL FILESYSTEM - ON. GCC version: " ${CMAKE_CXX_COMPILER_VERSION})
        # Подключение библиотеки для работы с filesystem
        set(LIB ${LIB} stdc++fs)
        option(EXPERIMENTAL_FILESYSTEM "Using experimental filesystem" ON)
    endif()
    # Подключение STD Threads
    find_package(Threads)
    set(LIB ${LIB} ${CMAKE_THREAD_LIBS_INIT})
    # Установка mime type = application/x-executable
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -no-pie")
    # Файл с командами под LINUX
    set(SHELL_FILE_NAME shell.sh)
endif()

# Путь к каталогу для исполнительных файлов
set(EXECUTABLE_OUTPUT_PATH ${EXE_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${EXE_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${EXE_OUTPUT_DIRECTORY})
# Путь к каталогу для динамически подключаемых библиотек
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${EXE_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${EXE_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${EXE_OUTPUT_DIRECTORY})
# Путь к каталогу для статических библиотек
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${EXE_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${EXE_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${EXE_OUTPUT_DIRECTORY})

# Стандарт языка
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

set(REFLEX_CPP_LIB)

# Исходные файлы проекта
set(CPP
    ./lib/RE-flex/lib/convert.cpp
    ./lib/RE-flex/lib/debug.cpp
    ./lib/RE-flex/lib/error.cpp
    ./lib/RE-flex/lib/input.cpp
    ./lib/RE-flex/lib/matcher_avx2.cpp
    ./lib/RE-flex/lib/matcher_avx512bw.cpp
    ./lib/RE-flex/lib/matcher.cpp
    ./lib/RE-flex/lib/pattern.cpp
    ./lib/RE-flex/lib/posix.cpp
    ./lib/RE-flex/lib/simd_avx2.cpp
    ./lib/RE-flex/lib/simd_avx512bw.cpp
    ./lib/RE-flex/lib/unicode.cpp
    ./lib/RE-flex/lib/utf8.cpp
    ./lib/RE-flex/unicode/block_scripts.cpp
    ./lib/RE-flex/unicode/language_scripts.cpp
    ./lib/RE-flex/unicode/letter_scripts.cpp
    ./src/interpreter/parser.cpp
    ./src/interpreter/scanner.cpp
    ./src/interpreter/action_tree.cpp
    ./src/interpreter/interpreter.cpp
    ./src/main_window/main_window.cpp
)

# Заголовочные файлы проекта
set(HPP
    ./lib/RE-flex/include/reflex/abslexer.h
    ./lib/RE-flex/include/reflex/absmatcher.h
    ./lib/RE-flex/include/reflex/bits.h
    ./lib/RE-flex/include/reflex/boostmatcher.h
    ./lib/RE-flex/include/reflex/convert.h
    ./lib/RE-flex/include/reflex/debug.h
    ./lib/RE-flex/include/reflex/error.h
    ./lib/RE-flex/include/reflex/flexlexer.h
    ./lib/RE-flex/include/reflex/input.h
    ./lib/RE-flex/include/reflex/matcher.h
    ./lib/RE-flex/include/reflex/pattern.h
    ./lib/RE-flex/include/reflex/pcre2matcher.h
    ./lib/RE-flex/include/reflex/posix.h
    ./lib/RE-flex/include/reflex/ranges.h
    ./lib/RE-flex/include/reflex/setop.h
    ./lib/RE-flex/include/reflex/simd.h
    ./lib/RE-flex/include/reflex/stdmatcher.h
    ./lib/RE-flex/include/reflex/timer.h
    ./lib/RE-flex/include/reflex/traits.h
    ./lib/RE-flex/include/reflex/unicode.h
    ./lib/RE-flex/include/reflex/utf8.h
    ./src/interpreter/parser.hpp
    ./src/interpreter/location.hpp
    ./src/interpreter/scanner.hpp
    ./src/interpreter/action_tree.hpp
    ./src/interpreter/interpreter.hpp
    ./src/main_window/main_window.hpp
)

# Инициализация графической библиотеки SCITER
message(STATUS "SKITER GUI LIBRARY INIT")

# Путь к заголовочным файлам графической библиотеки sciter
set(SCITER_SDK_INCLUDE ./lib/sciter-js-sdk/include)
# Подключение заголовочных файлов для графической библиотеки sciter
set(INCLUDES ${INCLUDES} ${SCITER_SDK_INCLUDE})
# Точка входа для графической библиотеки sciter
set(SCITER_SDK_MAIN)

if(WIN32) # Для Windows
    set(EXE_OPTIONS ${EXE_OPTIONS} WIN32) # Установка точки входа WinMain для GUI версии приложения
    set(SCITER_SDK_MAIN ${SCITER_SDK_MAIN} sciter-win-main.cpp) # Main sciter sdk для windows
elseif(UNIX) # Для Linux
    # Подключение GTK
    include(FindPkgConfig)
    PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

    include_directories(${GTK3_INCLUDE_DIRS})
    link_directories(${GTK3_LIBRARY_DIRS})
    add_definitions(${GTK3_CFLAGS_OTHER})

    set(LIB ${LIB} ${GTK3_LIBRARIES} dl)
    set(SCITER_SDK_MAIN ${SCITER_SDK_MAIN} sciter-gtk-main.cpp) # Main sciter sdk для linux
endif()

# Установка пути для файла с точкой входа графической библиотеки sciter
set(CPP_MAIN ${CPP_MAIN} ${SCITER_SDK_INCLUDE}/${SCITER_SDK_MAIN})
# Вывод пути к файлу с точкой входа графической библиотеки sciter
message(STATUS "SKITER main file path:" ${SCITER_SDK_INCLUDE}/${SCITER_SDK_MAIN})

# Создание директории bin
#FILE(MAKE_DIRECTORY ./bin ./build)

# Задача для запуска команд
ADD_CUSTOM_TARGET(SHELL_CMD ALL)

# Упаковка gui перед сборкой проекта
add_custom_command(TARGET SHELL_CMD
                    PRE_BUILD
                    COMMAND ./${SHELL_FILE_NAME}
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

# Каталоги с include файлами
include_directories(${INCLUDES})

# Создание исполняемого файла
add_executable(CALC++ ${EXE_OPTIONS} ${CPP_MAIN} ${CPP} ${HPP} ${RC})

add_dependencies(CALC++ SHELL_CMD)

# Подключение необходимых библиотек
target_link_libraries(CALC++ ${LIB})