cmake_minimum_required(VERSION 3.27)
project(GLIBChecker)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-W -Wall -Wextra -Werror -Wpedantic)

add_executable(glib_checker src/main.cpp
        src/GlibChecker.cpp
        src/GlibChecker.hpp
        src/Utilities/Utilities.cpp
        src/Utilities/Utilities.hpp)
