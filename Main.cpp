#include <iostream>
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "Main.h"

int boot::Main::main(int argc, char *argv[]) {
    // creating the server object
    MySerialServer *server = new MySerialServer();

    // Solver --> StringReverser
    // ‫‪CacheManager --> FileCacheManager
    StringReverser *strReverse = new StringReverser();
    FileCacheManager<string, string> *fileCM = new FileCacheManager<string, string>("fileCache.txt");

    MyTestClientHandler *mch = new MyTestClientHandler(strReverse, fileCM);

    // calling 'open' function in server
    server->open(atoi(argv[0]), mch);

    return 0;
}