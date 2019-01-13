//
// Created by david on 1/13/19.
//

#include "MyParallelServer.h"

MyParallelServer::MyParallelServer() {}

void MyParallelServer::open(int port, ClientHandler *c) {
    int sockfd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(sockfd, (struct sockaddr *) &address, sizeof(address));
    mySockfd = sockfd;
    listen(sockfd, 5);

    thread first(listenToClient, sockfd, address, addrlen, c);
    // wait for 'first' to finish
    first.join();
    // close the socket
    this->stop();
}

void MyParallelServer::stop() {
    cout << "Closing socket..." << endl;
    close(mySockfd);
}

void MyParallelServer::listenToClient(int sockfd, struct sockaddr_in address, int addrlen, ClientHandler *c) {
    int clientCounter = 0;
    int new_socket;
    bool flag = true;
    while (flag) {
        bool timeOut = true;
        // using lambda function - t1 => new thread
        std::thread t1([&]() {
            new_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);

            if (new_socket < 0) { // if ACCEPT fails
                perror("error");
                exit(EXIT_FAILURE);
            }
            // if ACCEPT succeeded - continue without Time-Out
            timeOut = false;
        });

        // allow execution to continue independently by 'detach'
        t1.detach();

        // the main is waiting 5 seconds and then checks the variable 'timeOut'
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // if ACCEPT failed after 5 seconds --> Time-Out
        if (timeOut && clientCounter == 0) {
            cout << "<<< TIME OUT >>>" << endl;
            flag = false; // exiting while loop
            break;
        }
        clientCounter++;
        std::thread t2([&]() {
            if (flag) // only if ACCEPT succeeded --> call 'handleClient'
                c->handleClient(new_socket);
            clientCounter--;
        });
        t2.detach();
    }
}