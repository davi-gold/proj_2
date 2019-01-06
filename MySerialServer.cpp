//
// Created by david on 1/3/19.
//

#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include "MySerialServer.h"

void MySerialServer::open(int port, ClientHandler *c) {
    int server_fd, new_socket, valread;
    //char buffer[1024];
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(server_fd, (struct sockaddr *) &address, sizeof(address));
    listen(server_fd, 5);
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                             (socklen_t*) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    //WILL OPEN A THREAD HERE
    //openReader(new_socket, buffer, readSpeed);
    //thread first();
    //first.detach();
}

void MySerialServer::stop(int port) {

}