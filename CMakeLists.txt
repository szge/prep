cmake_minimum_required(VERSION 3.26)
project(prep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch2_intro_to_fns
    notes/learncpp_com/ch2_intro_to_fns/main.cpp
    notes/learncpp_com/ch2_intro_to_fns/add.cpp
)

add_executable(ch2_quiz
    notes/learncpp_com/ch2_intro_to_fns/quiz.cpp
    notes/learncpp_com/ch2_intro_to_fns/io.cpp
)

add_executable(ch3_debugging
    notes/learncpp_com/ch3_debugging/main.cpp
)

add_executable(ch4_fundamental_types
    notes/learncpp_com/ch4_fundamental_types/main.cpp
)

add_executable(ch4_quiz
    notes/learncpp_com/ch4_fundamental_types/quiz.cpp
)

add_executable(ch4_quiz2
    notes/learncpp_com/ch4_fundamental_types/quiz2.cpp
)

add_executable(ch5_constants_strings
    notes/learncpp_com/ch5_constants_strings/main.cpp
#    notes/learncpp_com/ch5_constants_strings/string_view.cpp
)

add_executable(ch5_quiz
    notes/learncpp_com/ch5_constants_strings/quiz.cpp
)