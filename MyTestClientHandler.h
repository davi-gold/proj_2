//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_MYTESTCLIENTHANDLER_H
#define PROJ_2_MYTESTCLIENTHANDLER_H



#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
    virtual void handleClient(ifstream is, ofstream os);
};
#endif //PROJ_2_MYTESTCLIENTHANDLER_H
