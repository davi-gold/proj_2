cmake_minimum_required(VERSION 3.12)
project(proj_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj_2 main.cpp MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Server.h CacheManager.h Solver.h Problem.cpp Problem.h Solution.cpp Solution.h)