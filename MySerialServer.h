//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_MYSERIALSERVER_H
#define PROJ_2_MYSERIALSERVER_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include "Server.h"

class MySerialServer : public server_side::Server {
public:
    virtual void open(int port, ClientHandler *c);
    static void listenToClient(int server_fd, struct sockaddr_in address, int addrlen, ClientHandler *c);
    virtual void stop(int port);
};


#endif //PROJ_2_MYSERIALSERVER_H
