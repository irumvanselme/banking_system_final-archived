cmake_minimum_required(VERSION 3.22)
project(banking_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(banking_system main.cpp models.cpp utils/Service.cpp services/account-service.cpp utils/headers.h)
