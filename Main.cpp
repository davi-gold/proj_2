#include <iostream>
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "Main.h"
#include "MatrixSearchable.h"
#include "ISearcher.h"
#include "BestFirstSearch.h"
#include "StringableString.h"
#include "ISearchable.h"
#include "BFS.h"
#include "MyClientHandler.h"
#include "DFS.h"


using Point =std::pair<int,int>;

int boot::Main::main(int argc, char *argv[]) {
    // creating the server object
    server_side::Server *server = new MySerialServer();

    vector<string> myVec;
    myVec.push_back("1,2,3");
    myVec.push_back("4,5,6");
    // myVec.push_back("7,8,9");
    MatrixSearchable *matrix = new MatrixSearchable();
    matrix->setMatrix(myVec);
    matrix->setInitialState("0,0");
    matrix->setGoalState("1,2");

    CacheManager<MatrixSearchable*, StringableString> *fileCM =
           new FileCacheManager<MatrixSearchable*, StringableString>("fileCache.txt");

    Searcher<StringableString, Point> *srch = new DFS<StringableString, Point>();

    Solver<MatrixSearchable*, StringableString> *slvr = new MatrixSolver<StringableString>(srch);


    ClientHandler *mch = new MyClientHandler(slvr, fileCM);
//
//     calling 'open' function in server
    server->open(atoi(argv[1]), mch);
    while(true){};

    return 0;
}