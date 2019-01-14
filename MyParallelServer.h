//
// Created by david on 1/13/19.
//

#ifndef PROJ_2_MYPARALLELSERVER_H
#define PROJ_2_MYPARALLELSERVER_H


#include <iostream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include "Server.h"

class MyParallelServer : public server_side::Server {
    int mySockfd;

public:
    MyParallelServer();
    virtual void open(int port, ClientHandler *c);
    static void listenToClient(int server_fd, struct sockaddr_in address, int addrlen, ClientHandler *c);
    virtual void stop();
};



#endif //PROJ_2_MYPARALLELSERVER_H
