#include <iostream>
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "Main.h"
//#include "Searcher.h"
#include "MatrixSearchable.h"
#include "ISearcher.h"
#include "BestFirstSearch.h"
#include "StringableString.h"
#include "ISearchable.h"


using Point =std::pair<int,int>;

int boot::Main::main(int argc, char *argv[]) {
/*
    // creating the server object
    server_side::Server *server = new MySerialServer();

    // Solver --> StringReverser
    // ‫‪CacheManager --> FileCacheManager
    StringReverser *strReverse = new StringReverser();
    CacheManager<string, string> *fileCM = new FileCacheManager<string, string>("fileCache.txt");

    ClientHandler *mch = new MyTestClientHandler(strReverse, fileCM);

    // calling 'open' function in server
    server->open(atoi(argv[1]), mch);
    while(true){};*/
    vector<string> myVec;
    myVec.push_back("1,2,3");
    myVec.push_back("4,5,6");
    MatrixSearchable *matrix = new MatrixSearchable();
    matrix->setMatrix(myVec);
    matrix->setInitialState("1,1");
    matrix->setGoalState("1,0");

    ISearcher<string, Point> *srch = new BestFirstSearch<string, Point>();
    string sol = srch->search(matrix);


    return 0;
}