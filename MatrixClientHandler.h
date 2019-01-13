//
// Created by daniella on 1/11/19.
//

#ifndef PROJ_2_MATRIXCLIENTHANDLER_H
#define PROJ_2_MATRIXCLIENTHANDLER_H


#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
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
                    if (problemTemp == "end") {
                        switchFlag = false;
                    }
                    // as long as it is not end of line -> update the string
                    else if (buffer[i] != '\r' && buffer[i + 1] != '\n') {

                        problemTemp += buffer[i];
                        //client finished entering message
                    }  else {
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
        bool finish = false;
        string end = "end";
        vector<string> fromClient;
        while (!finish) {
            fromClient = readFromSocket(socket);
            if (this->cm->isSaved(fromClient)) {
                string sol = this->cm->getSolution(fromClient);
                // send the solution to client
                const char *fromClientChar = sol.c_str(); // convert the string to char *
                send(socket, fromClientChar, strlen(fromClientChar), 0); // write to client
            } else {
                string solution = this->solver->solve(fromClient); // solve the problem
                this->cm->saveSolution(fromClient, solution); // save the solution
                const char *solutionChar = solution.c_str(); // convert the string to char *
                send(socket, solutionChar, strlen(solutionChar), 0); // write to client
            }
        } close(socket);
    }
};


#endif //PROJ_2_MATRIXCLIENTHANDLER_H
