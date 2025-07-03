cmake_minimum_required(VERSION 3.26)
project(prep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(misc
        misc.cpp
)

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

add_executable(ch6_operators
    notes/learncpp_com/ch6_operators/main.cpp
)

add_executable(ch6_quiz
    notes/learncpp_com/ch6_operators/quiz.cpp
)

add_executable(chO_bit_manipulation
    notes/learncpp_com/chO_bit_manipulation/main.cpp
)

add_executable(ch7_scope_duration_linkage
    notes/learncpp_com/ch7_scope_duration_linkage/main.cpp
)

add_executable(ch8_control_flow
    notes/learncpp_com/ch8_control_flow/main.cpp
)

add_executable(ch8_quiz1
    notes/learncpp_com/ch8_control_flow/quiz1.cpp
)

add_executable(ch8_quiz2
    notes/learncpp_com/ch8_control_flow/quiz2.cpp
)

add_executable(ch8_quiz3
    notes/learncpp_com/ch8_control_flow/quiz3.cpp
)

add_executable(ch9_testing
    notes/learncpp_com/ch9_testing/main.cpp
)

add_executable(ch10_types
    notes/learncpp_com/ch10_types/main.cpp
)

add_executable(ch10_quiz
    notes/learncpp_com/ch10_types/quiz1.cpp
)

add_executable(ch11_fn_overloading_templates
    notes/learncpp_com/ch11_fn_overloading_templates/main.cpp
)

add_executable(ch11_quiz notes/learncpp_com/ch11_fn_overloading_templates/quiz.cpp)

add_executable(chF notes/learncpp_com/chF_constexpr_fns/main.cpp)
add_executable(chF_quiz notes/learncpp_com/chF_constexpr_fns/quiz.cpp)