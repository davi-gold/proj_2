//
// Created by david on 1/3/19.
//

#include <sys/socket.h>
#include <cstring>
#include "MyTestClientHandler.h"

// constructor
MyTestClientHandler::MyTestClientHandler(Solver *s, CacheManager *c) {
    this->solver = s;
    this->cm = c;
}

// function: gets socket and return the message received from socket until end of line
string readFromSocket(int socket) {
    bool switchFlag = true;
    string problemTemp;
    string problemFinal;
    // read continuously from socket
    while (switchFlag == true) {
        // first, read all data from socket into buffer
        char[256] buffer;
        int messageLength = recv(socket, buffer, sizeof(buffer), 0);
        // if the message from client is not empty
        if (messageLength > 0) {
            // iterate over the buffer to find end of line
            for (int i = 0; i < messageLength; i++) {
                // as long as it is not end of line -> update the string
                if (buffer[i] != '\n')
                    problemTemp += buffer[i];
                else {
                    // if it is end of line and problem is not empty -> update the final string
                    if (problemTemp.length() > 0) {
                        // copy content from problemTemp to problemFinal
                        for (int j = 0; j < problemTemp.length(); j++)
                            problemFinal[j] = problemTemp[j];
                        problemTemp = "";
                        switchFlag = false;
                    } else {
                        perror("string is invalid\n");
                        return nullptr;
                    }
                }
            }
        } else {
            perror("message from socket is empty\n");
            return nullptr;
        }
    }
    if (!problemFinal.empty())
        return problemFinal;
    else {
        perror("the string 'problem' is emtpy\n");
        return nullptr;
    }
}

// overridden virtual function
void handleClient(int socket) {
    bool finish = false;
    string end = {"end"};
    string fromClient;
    while (finish == false){
        fromClient = readFromSocket(socket);
        if(!fromClient.strcmp(end));
    }

}
