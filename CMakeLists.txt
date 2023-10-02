cmake_minimum_required(VERSION 3.10)

project(isprime CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mtune=native -march=native -Wall")

add_executable(isprime isprime.cpp miller_rabin.cpp)
target_link_libraries(isprime gmp gmpxx)
