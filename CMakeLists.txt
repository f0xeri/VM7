cmake_minimum_required(VERSION 3.17)
project(VM7)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(VM7 main.cpp Processor.cpp Processor.h Commands.cpp Commands.h Registers.h Memory.cpp Memory.h Types.h Loader.cpp Loader.h IntegerMath.h RealMath.h Move.h Compare.h BitwiseOperations.h)