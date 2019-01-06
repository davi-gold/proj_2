//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_MYTESTCLIENTHANDLER_H
#define PROJ_2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"

class MyTestClientHandler : public ClientHandler {
    // members declarations
    Solver *solver;
    CacheManager *cm;

public:
    // constructor and functions declarations
    MyTestClientHandler(Solver *s, CacheManager *c);
    string readFromSocket(int socket);
    void handleClient(int socket) override;
};

#endif //PROJ_2_MYTESTCLIENTHANDLER_H
