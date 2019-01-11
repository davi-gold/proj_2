//
// Created by daniella on 1/11/19.
//

#ifndef PROJ_2_MATRIXCLIENTHANDLER_H
#define PROJ_2_MATRIXCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "MatrixSearchable.h"
#include "MatrixSolver.h"

class MatrixClientHandler : public ClientHandler {

    Solver<MatrixSearchable, string> *solver;
    CacheManager<string, string> *cm;
public:
    MatrixClientHandler(Solver<MatrixSearchable, string> *s,
                        CacheManager<string, string> *c) {
        solver = s;
        cm = c;
    };

    vector<string> readFromSocket(int socket) {
        bool switchFlag = true;
        string problemTemp;
        vector<string> problemFinal;
        // read continuously from socket
        while (switchFlag) {
            // first, read all data from socket into buffer
            char buffer[256];
            int messageLength = recv(socket, buffer, sizeof(buffer), 0);
            // if the message from client is not empty
            if (messageLength > 0) {
                // iterate over the buffer to find end of line
                for (int i = 0; i < messageLength; i++) {
                    // as long as it is not end of line -> update the string
                    if (buffer[i] != '\r' && buffer[i + 1] != '\n') {

                        problemTemp += buffer[i];
                        //client finished entering message
                    } else if (problemTemp == "end") {
                        switchFlag = false;
                    } else {
                        // if it is end of line and problem is not empty -> update the final string
                        if (problemTemp.length() > 0) {
                            // copy content from problemTemp to problemFinal
                            problemFinal.push_back(problemTemp);
                            problemTemp = "";
                        } else {
                            perror("string is invalid\n");
                            vector<string> bad;
                            return bad;
                        }
                    }
                }
            } else {
                perror("message from socket is empty\n");
                vector<string> bad;
                return bad;
            }
        }
        if (!problemFinal.empty())
            return problemFinal;
        else {
            perror("the string 'problem' is empty\n");
            vector<string> bad;
            return bad;
        }
    }

    virtual void handleClient(int socket) override {

    }
};


#endif //PROJ_2_MATRIXCLIENTHANDLER_H
