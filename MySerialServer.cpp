//
// Created by david on 1/3/19.
//

#include "MySerialServer.h"

MySerialServer::MySerialServer() {}

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
    mySockfd = server_fd;

    thread first(listenToClient, server_fd, address, addrlen, c);
    first.detach();


    //WILL OPEN A THREAD HERE

}

void MySerialServer::listenToClient(int server_fd, struct sockaddr_in address, int addrlen, ClientHandler *c) {
    int new_socket;

    while (true) {
        listen(server_fd, 10);
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("error");
            exit(EXIT_FAILURE);
        }

        c->handleClient(new_socket);
        //sleep here??
        //this_thread::sleep_for(chrono::milliseconds(int(250)));
    }
}

void MySerialServer::stop() {
    close(mySockfd);
}