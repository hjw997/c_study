cmake_minimum_required(VERSION 3.26)
project(c_study)

set(CMAKE_C_STANDARD 11)

add_executable(1_进制基础_src_a_main 1_进制基础/src/a_main.cpp)
add_executable(2_查看内存_验证小端模式在内存中的存放_src_a_main 2_查看内存_验证小端模式在内存中的存放/src/a_main.cpp)
add_executable(3_char_知多少_src_a_char_main 3_char_知多少/src/a_char_main.cpp)
add_executable(4_转义字符_a_main 4_转义字符/a_main.cpp)

add_executable(5_scanf_函数_src_a_scanf 5_scanf_函数/src/a_scanf.cpp)
add_executable(8_数组_src_array_test1 8_数组/src/array_test1.cpp)