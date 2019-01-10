#include <iostream>
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "Main.h"

#include <vector>

int boot::Main::main(int argc, char *argv[]) {

    // creating the server object
    server_side::Server *server = new MySerialServer();

    // Solver --> StringReverser
    // ‫‪CacheManager --> FileCacheManager
    StringReverser *strReverse = new StringReverser();
    CacheManager<string, string> *fileCM = new FileCacheManager<string, string>("fileCache.txt");

    ClientHandler *mch = new MyTestClientHandler(strReverse, fileCM);

    // calling 'open' function in server
    server->open(atoi(argv[1]), mch);
    while(true){};
    /*vector<string> myVec;
    myVec.push_back("1, ,2, 3");
    myVec.push_back("4, ,5 ,6");
    myVec.push_back("7, ,8, 9");*/


    return 0;
}