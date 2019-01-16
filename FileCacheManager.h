//
// Created by daniella on 1/6/19.
//

#ifndef PROJ_2_FILECACHMANAGER_H
#define PROJ_2_FILECACHMANAGER_H


#include "CacheManager.h"
#include <map>
#include <fstream>
#include <vector>
#include "Stringable.h"

using namespace std;

template<class P, class S>

class FileCacheManager : public CacheManager<P, S> {
    map<vector<string>, vector<string>> probSol;
    string fileName;

public:

    FileCacheManager(const string fName) {
        fileName = fName;
        createMap();
    };

    virtual bool isSaved(P p) {
        vector<string> pVec = p->convertToString();
        for (std::map<vector<string>, vector<string>>::iterator it=probSol.begin(); it!=probSol.end(); ++it) {
            if (it->first == pVec) {
                return true;
            }
        }
        return false;
    };

    virtual S* getSolution(P p) {
        S sol;
        vector<string> pVec = p->convertToString();
        for (std::map<vector<string>, vector<string>>::iterator it=probSol.begin(); it!=probSol.end(); ++it) {
            if (it->first == pVec) {
                vector<string> temp = it->second;
                sol.convertFromString(temp);
                S *pSol = &sol;
                return pSol;
            }
        }
        throw "no saved solution for that problem";
    };

    virtual void saveSolution(P p, S s) {
        vector<string> prob = p->convertToString();
        vector<string> sol = s.convertToString();

        probSol.insert(pair<vector<string>, vector<string>>(prob, sol));

        ofstream myFile(fileName, ios::app);

        //want to append the file
        if(myFile.is_open()){
            //saving number of problem rows and problem
            myFile<<prob.size()<<endl;
            for(int i = 0;i<prob.size();i++){
                myFile<<prob[i]<<endl;
            }
            //saving number of rows in solution and solution
            myFile<<sol.size()<<endl;
            for(int j = 0;j<sol.size();j++){
                myFile<<sol[j]<<endl;
            }
            myFile.close();
        }
    };

    //NEED TO UPDATE THIS
    void createMap() {
        ifstream myFile(fileName);
        string line;
        P prob;
        S sol;
        string temp;
        vector<string> stringsVec;
        if (myFile.is_open()) {
            unsigned long int objsNum;
           while(getline(myFile, line)){
                stringsVec.emplace_back(line);
           }
            myFile.close();
        }
        for(int i = 0;i<stringsVec.size();i++){
            //problem size
            int probSize = stoi(stringsVec[i].c_str());
            vector<string> probVec;
            //j will strat one row below i which equal the number of rows of the problem
            for(int j = i+1;j<probSize;j++){
                probVec.emplace_back(stringsVec[j]);
            }
            i+=probSize;
            //solution size
            int solSize = stoi(stringsVec[i].c_str());
            vector<string> solVec;
            //k will start from row below the solution size
            for(int k = i;k<solSize;k++){
                solVec.emplace_back(stringsVec[k]);
            }
            i+=solSize;
            //inserting problem and solution
            probSol.insert(pair<vector<string>, vector<string>>(probVec, solVec));
        }

    };

};


#endif //PROJ_2_FILECACHMANAGER_H
