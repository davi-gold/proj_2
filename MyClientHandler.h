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
#include "StringableString.h"

using Point =std::pair<int, int>;

class MyClientHandler : public ClientHandler {

    Solver<MatrixSearchable*, StringableString> *solver;
    CacheManager<MatrixSearchable*, StringableString> *cm;
public:
    MyClientHandler(Solver<MatrixSearchable*, StringableString> *s,
                    CacheManager<MatrixSearchable*, StringableString> *c) {
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
                for (int i = 0; i < messageLength-1; i++) {
                    if (problemTemp == "end") {
                        switchFlag = false;
                    }
                        // as long as it is not end of line -> update the string
                    else if (buffer[i] != '\r' && buffer[i + 1] != '\n') {

                        problemTemp += buffer[i];
                        //client finished entering message
                    } else {
                        // if it is end of line and problem is not empty -> update the final string
                        if (problemTemp.length() > 0) {
                            // copy content from problemTemp to problemFinal
                            problemFinal.push_back(problemTemp);
                            problemTemp = "";
                            //memset(buffer, 0, sizeof(buffer));
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
        int i = 1;
        bool finish = false;
        //string end = "end";
        vector<string> fromClient;
        fromClient = readFromSocket(socket);

        //creating MatrixSearchable from string vector
        MatrixSearchable myMat = MatrixSearchable();
        myMat.convertFromString(fromClient);
        if (this->cm->isSaved((&myMat))) {
            //myMat solution returns a string
            StringableString sol = *(this->cm->getSolution(&myMat));
            string solution = sol.getString();
            solution+="\r\n";

            // send the solution to client
            const char *fromClientChar = solution.c_str(); // convert the string to char *
            send(socket, fromClientChar, strlen(fromClientChar), 0); // write to client
            //still haven't solved this problem
        } else {
            StringableString *pSol = this->solver->solve(&myMat);
            StringableString sol = *pSol;
            // save the solution
            vector<string> myMatStrings = myMat.convertToString();
            this->cm->saveSolution(&myMat, sol);
            string solString = sol.getString();
            solString+="\r\n";
            const char *solutionChar = solString.c_str(); // convert the string to char *
            send(socket, solutionChar, strlen(solutionChar), 0); // write to client
        }
        close(socket);
    }

    string convertVectorToString(vector<string> myVec) {
        string vecString = {};
        for (int i = 0; i < myVec.size(); i++) {
            vecString.append(myVec[i]);
        }
        return vecString;
    }
};


#endif //PROJ_2_MATRIXCLIENTHANDLER_H
