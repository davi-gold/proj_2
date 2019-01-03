//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_SERVER_H
#define PROJ_2_SERVER_H
namespace
‫‪server_side
‬{
class ;
}

class server_side::Server {
    virtual void open(int port) = 0;

    virtual void stop(int port) = 0;
};

#endif //PROJ_2_SERVER_H
