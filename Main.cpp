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
#include "Experiment.h"


using Point =std::pair<int, int>;

int boot::Main::main(int argc, char *argv[]) {
// creating the server object
//    server_side::Server *server = new MySerialServer();
//
//    vector<string> myVec;
//    myVec.push_back("1,2,3");
//    myVec.push_back("4,5,6");
//    myVec.push_back("7,8,9");
//    MatrixSearchable *matrix = new MatrixSearchable();
//    matrix->setMatrix(myVec);
//    matrix->setInitialState("0,0");
//    matrix->setGoalState("1,2");
//
//    CacheManager<MatrixSearchable*, StringableString> *fileCM =
//           new FileCacheManager<MatrixSearchable*, StringableString>("fileCache.txt");
//
//    Searcher<StringableString, Point> *srch = new DFS<StringableString, Point>();
//
//    Solver<MatrixSearchable*, StringableString> *slvr = new MatrixSolver<StringableString>(srch);
//
//
//    ClientHandler *mch = new MyClientHandler(slvr, fileCM);
//
//     calling 'open' function in server
//    server->open(atoi(argv[1]), mch);
//    while(true){};

    Experiment *exp = new Experiment(argv);
    exp->run();

    return 0;
}
//#include <iostream>
//#include "MySerialServer.h"
//#include "FileCacheManager.h"
//#include "Main.h"
//#include "MatrixSearchable.h"
//#include "ISearcher.h"
//#include "BestFirstSearch.h"
//#include "StringableString.h"
//#include "ISearchable.h"
//#include "BFS.h"
//#include "MyClientHandler.h"
//#include "DFS.h"
//#include "Astar.h"
//
//
//using Point =std::pair<int, int>;
//
//int boot::Main::main(int argc, char *argv[]) {
//
//    vector<string> myVec;
//    myVec.push_back("6,6,9,1,10,3,5,2,4,1");
//    myVec.push_back("1,1,3,8,1,3,1,7,4,2");
//    myVec.push_back("7,8,9");
//    MatrixSearchable *matrix = new MatrixSearchable();
//    matrix->setMatrix(myVec);
//    matrix->setInitialState("0,0");
//    matrix->setGoalState("2,2");
//
//    myVec.push_back("1,2,3");
//    myVec.push_back("4,5,6");
//    myVec.push_back("7,8,9");
//    MatrixSearchable *matrix1 = new MatrixSearchable();
//    matrix1->setMatrix(myVec);
//    matrix1->setInitialState("0,0");
//    matrix1->setGoalState("2,2");
//
//    myVec.push_back("1,2,3");
//    myVec.push_back("4,5,6");
//    myVec.push_back("7,8,9");
//    MatrixSearchable *matrix2 = new MatrixSearchable();
//    matrix2->setMatrix(myVec);
//    matrix2->setInitialState("0,0");
//    matrix2->setGoalState("2,2");
//
//    myVec.push_back("1,2,3");
//    myVec.push_back("4,5,6");
//    myVec.push_back("7,8,9");
//    MatrixSearchable *matrix3 = new MatrixSearchable();
//    matrix3->setMatrix(myVec);
//    matrix3->setInitialState("0,0");
//    matrix3->setGoalState("2,2");
//
//
//    Searcher<StringableString, Point> *srch = new DFS<StringableString, Point>();
//    StringableString *sol = srch->search(matrix);
//    std::cout << "* * * * * * * * * *" << std::endl;
//    std::cout << "D F S" << std::endl;
//    std::cout << sol->getString() << std::endl;
//    std::cout << "* * * * * * * * * *" << std::endl;
//
//    Searcher<StringableString, Point> *srch1 = new BFS<StringableString, Point>();
//    StringableString *sol1 = srch1->search(matrix1);
//    std::cout << "B F S" << std::endl;
//    std::cout << sol1->getString() << std::endl;
//    std::cout << "* * * * * * * * * *" << std::endl;
//
//    Searcher<StringableString, Point> *srch2 = new BestFirstSearch<StringableString, Point>();
//    StringableString *sol2 = srch2->search(matrix2);
//    std::cout << "Best-First-Search" << std::endl;
//    std::cout << sol2->getString() << std::endl;
//    std::cout << "* * * * * * * * * *" << std::endl;
//
//    Searcher<StringableString, Point> *srch3 = new Astar<StringableString, Point>();
//    StringableString *sol3 = srch3->search(matrix3);
//    std::cout << "A-star" << std::endl;
//    std::cout << sol3->getString() << std::endl;
//    std::cout << "* * * * * * * * * *" << std::endl;
//
//
//    return 0;
//}