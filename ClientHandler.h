//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_CLIENTHANDLER_H
#define PROJ_2_CLIENTHANDLER_H

#include <fstream>

using namespace std;

class ClientHandler {
    virtual void handleClient(ifstream is, ofstream os) = 0;
};

#endif //PROJ_2_CLIENTHANDLER_H
