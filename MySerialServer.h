//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_MYSERIALSERVER_H
#define PROJ_2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public server_side::Server {
public:
    virtual void open(int port, ClientHandler *c);
    virtual void stop(int port);
};


#endif //PROJ_2_MYSERIALSERVER_H
