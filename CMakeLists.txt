cmake_minimum_required(VERSION 3.10)
project(XO)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        main.cpp
        )

add_executable(XO_Run ${SOURCE_FILES})

add_subdirectory(src)

target_link_libraries(XO_Run XO_Lib)