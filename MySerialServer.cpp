//
// Created by david on 1/3/19.
//

#include "MySerialServer.h"

MySerialServer::MySerialServer() {}

void MySerialServer::open(int port, ClientHandler *c) {
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

void MySerialServer::stop() {
    cout << "Closing socket..." << endl;
    close(mySockfd);
}

void MySerialServer::listenToClient(int sockfd, struct sockaddr_in address, int addrlen, ClientHandler *c) {
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
        if (timeOut) {
            cout << "<<< TIME OUT >>>" << endl;
            flag = false; // exiting while loop
        }
        if (flag) // only if ACCEPT succeeded --> call 'handleClient'
            c->handleClient(new_socket);
    }
}
