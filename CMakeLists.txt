cmake_minimum_required(VERSION 3.11)

project(figure1 CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Подключаем googletest
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Объявляем библиотеку
add_library(figure1 SHARED
    "include/figure1/figure1.h"
    "src/figure1.cc"
    "src/figure1_list.cc"
 )
target_include_directories(figure1 PUBLIC "include")

# Объявляем тесты
add_executable(figure1_tests
    "tests/figure1_list_tests.cc"
    "tests/figure1_tests.cc"
)
target_link_libraries(figure1_tests figure1 GTest::gtest_main)
# Объявляем исполняемый файл
add_executable(main "include/figure1/menu_figure1.h" "src/menu_figure1.cc" "src/main.cc")
target_link_libraries(main figure1)