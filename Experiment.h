//
// Created by david on 1/16/19.
//

#ifndef PROJ_2_EXPERIMENT_H
#define PROJ_2_EXPERIMENT_H

#include <iostream>
#include <fstream>
#include "MatrixSearchable.h"
#include "ISearcher.h"
#include "BestFirstSearch.h"
#include "StringableString.h"
#include "ISearchable.h"
#include "BFS.h"
#include "DFS.h"
#include <fstream>
#include <sstream>

#define ENDOFSTRING '\0'
using namespace std;

class Experiment {
    string filePath;
    vector<MatrixSearchable *> matVec;

public:
    Experiment(char *file[]) { this->filePath = file[1]; }

    void loadMatrices() {
        ifstream inFile;
        inFile.open(this->filePath); // open the input file

        stringstream strStream;
        strStream << inFile.rdbuf(); // read the file
        string fileStr = strStream.str(); // str holds the content of the file

        string initial;
        string goal;
        int i = 0;
        int size;
        string line;

            for (int m = 0; m < 10; m++) {
                vector<string> mat;

                // configure size
                while (fileStr[i] != '\n') {
                    line += fileStr[i];
                    i++;
                }
                size = std::stoi(line);
                line = "";
                i++;
                int numOfLines = 0;

                // reading lines
                while (numOfLines < size) {
                    while (fileStr[i] != '\n') {
                        line += fileStr[i];
                        i++;
                    }
                    numOfLines++;
                    mat.push_back(line);
                    line = "";
                    i++;
                }

                // configure initial and goal
                while (fileStr[i] != '\n') {
                    line += fileStr[i];
                    i++;
                }
                initial = line;
                line = "";
                i++;

                while (fileStr[i] != '\n') {
                    line += fileStr[i];
                    i++;
                }
                goal = line;
                line = "";
                i++;

                // create matrix
                MatrixSearchable *matrix = new MatrixSearchable();
                matrix->setMatrix(mat);
                matrix->setInitialState(initial);
                matrix->setGoalState(goal);

                this->matVec.push_back(matrix);
                m++;
            }
    }

    void run(){
        this->loadMatrices();
        for(int i = 0; i < this->matVec.size(); i++)

    }
};


#endif //PROJ_2_EXPERIMENT_H
