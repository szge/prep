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