//
// Created by david on 1/3/19.
//

#include "MySerialServer.h"

MySerialServer::MySerialServer() {}

void MySerialServer::open(int port, ClientHandler *c) {
    int sockfd, new_socket, valread;
    //char buffer[1024];
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(sockfd, (struct sockaddr *) &address, sizeof(address));
    mySockfd = sockfd;
//    listenToClient(sockfd,address,addrlen,c);
    thread first(listenToClient, sockfd, address, addrlen, c);
    first.detach();


    //WILL OPEN A THREAD HERE

}

void MySerialServer::listenToClient(int sockfd, struct sockaddr_in address, int addrlen, ClientHandler *c) {
    int new_socket;

    while (true) {
        listen(sockfd, 5);
        if ((new_socket = accept(sockfd, (struct sockaddr *) &address,
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