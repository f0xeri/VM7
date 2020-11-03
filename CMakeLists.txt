cmake_minimum_required(VERSION 3.17)
project(VM7)

set(CMAKE_CXX_STANDARD 17)

add_executable(VM7 main.cpp Processor.cpp Processor.h Commands.cpp Commands.h Registers.h Structs.h Memory.cpp Memory.h Types.h Loader.cpp Loader.h IntegerMath.h Real.h)