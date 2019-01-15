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
#include "BFS.h"


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
   // myVec.push_back("7,8,9");
    MatrixSearchable *matrix = new MatrixSearchable();
    matrix->setMatrix(myVec);
    matrix->setInitialState("0,0");
    matrix->setGoalState("1,2");

    //list<State<Point> *> posS = matrix->getAllPossibleStates(matrix->getInitialState());

    Searcher<string, Point> *srch = new BFS<string, Point>();
    string sol = srch->search(matrix);

    return 0;
}