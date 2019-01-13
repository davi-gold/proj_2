cmake_minimum_required(VERSION 3.12)
project(proj_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj_2 MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Server.h CacheManager.h Solver.h Problem.cpp Problem.h Solution.cpp Solution.h StringReverser.cpp StringReverser.h FileCacheManager.h Main.cpp Main.h main.cpp Searchable.h State.cpp State.h Searcher.cpp Searcher.h ISearcher.h BestFirstSearch.cpp BestFirstSearch.h ISearchable.h DFS.h MatrixSearchable.h MatrixSolver.h MatrixClientHandler.h MyParallelServer.cpp MyParallelServer.h BFS.cpp BFS.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")