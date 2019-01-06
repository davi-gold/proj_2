//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_SERVER_H
#define PROJ_2_SERVER_H

#include "ClientHandler.h"

class Server {
    virtual void open(int port, ClientHandler *c) = 0;
    virtual void stop() = 0;
};

#endif //PROJ_2_SERVER_H