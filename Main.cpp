#include <iostream>
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "Main.h"

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

    return 0;
}