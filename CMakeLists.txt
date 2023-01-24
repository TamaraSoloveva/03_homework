cmake_minimum_required(VERSION 3.15)

project(03_homework CXX)

add_executable(03_homework
    main.cpp
    rand_value.cpp
    rand_value.h

)

set_target_properties(03_homework PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
  CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    target_compile_options(03_homework PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

    target_compile_options(03_homework PRIVATE /EHsc /W4 /WX)

endif()


