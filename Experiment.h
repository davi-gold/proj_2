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
#include "Astar.h"
#include <fstream>
#include <sstream>

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
        }
    }

    void run() {
        this->loadMatrices();

        Searcher<StringableString, Point> *bestFirstSearch = new BestFirstSearch<StringableString, Point>();
        Searcher<StringableString, Point> *astar = new Astar<StringableString, Point>();
        Searcher<StringableString, Point> *dfs = new DFS<StringableString, Point>();
        Searcher<StringableString, Point> *bfs = new BFS<StringableString, Point>();

        for (int i = 0; i < this->matVec.size(); i++) {
//            std::cout << "Matrix number " << i + 1 << "\n" << endl;
            // best first search
//            MatrixSearchable mat_bestfs = *matVec[i];
//            StringableString *bestfs = bestFirstSearch->search(&mat_bestfs);
//            int pathCostBest = mat_bestfs.getGoal()->getCostPath();
//            int nodesEvalBest = bestFirstSearch->getNumOfNodesEval();
//            std::cout << "<< BEST FIRST SEARCH>> " << endl;
//            cout << "\n" << bestfs->getString() << endl;
//            std::cout << "PATHCOST     NODES" << endl;
//            std::cout << pathCostBest << "           " << nodesEvalBest << endl;

//            MatrixSearchable mat_astar = *matVec[i];
//            StringableString *a = astar->search(&mat_astar);
//            int pathCostAstar = mat_astar.getGoal()->getCostPath();
//            int nodesEvalAstar = astar->getNumOfNodesEval();
//            std::cout << "\n<< A* >> " << endl;
//            cout << "\n" << a->getString() << endl;
//            std::cout << "PATHCOST     NODES" << endl;
//            std::cout << pathCostAstar << "           " << nodesEvalAstar << endl;


//            MatrixSearchable mat_DFS = *matVec[i];
//            StringableString *dfsS = dfs->search(&mat_DFS);
//            int pathCostDFS = mat_DFS.getGoal()->getCostPath();
//            int nodesEvalDFS = dfs->getNumOfNodesEval();
//            std::cout << "\n<< DFS >> " << endl;
//            cout << dfsS->getString() << endl;
//            std::cout << "PATHCOST     NODES" << endl;
//            std::cout << pathCostDFS << "           " << nodesEvalDFS << endl;

//            MatrixSearchable mat_BFS = *matVec[i];
//            StringableString *bfsS evalNodes= bfs->search(&mat_BFS);
//            int pathCostBFS = mat_BFS.getGoal()->getCostPath();
//            int nodesEvalBFS = bfs->getNumOfNodesEval();
//            std::cout << "\n<< BFS >> " << endl;
//            cout << bfsS->getString() << endl;
//            std::cout << "PATHCOST     NODES" << endl;
//            std::cout << pathCostBFS << "           " << nodesEvalBFS << endl;

            MatrixSearchable mat = *matVec[i];
            StringableString *dfsS = bestFirstSearch->search(&mat);
            int pathCost = mat.getGoal()->getCostPath();
//            std::cout << "<< DFS >> " << endl;
//            std::cout << "PATHCOST" << endl;
            std::cout << pathCost << endl;
        }
    }
};


#endif //PROJ_2_EXPERIMENT_H
