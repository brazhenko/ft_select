cmake_minimum_required(VERSION 3.13)
project(ft_select)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)
add_executable(ft_select src/ft_select.c src/tty_configure.c src/key_commands.c)