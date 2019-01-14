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
    map<P, S> probSol;
    map<string, string> stringPSMap;
    string fileName;

public:

    FileCacheManager(const string fName) {
        fileName = fName;
        createMap();
    };

    virtual bool isSaved(P p) {
        for (typename::map<P, S>::iterator it = probSol.begin(); it != probSol.end(); ++it) {
            if (it->first == p) {
                return true;
            }
        }
        return false;
    };

    virtual S getSolution(P p) {
        for (typename::map<P, S>::iterator it = probSol.begin(); it != probSol.end(); ++it) {
            if (it->first == p) {
                string temp = it->second;
                temp.push_back('\n');
                return temp;
            }
        }
        throw "no saved solution for that problem";
    };

    virtual void saveSolution(P p, S s) {
        probSol.insert(pair<P, S>(p, s));
        //NEED TO USE WTVR METHOD I CHOOSE TO CONVERT P AND S TO STRINGS INSTEAD OF 2 ROWS BELOW
        vector<string> prob = p.convertToString();
        vector<string> sol = s.convertToString();
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
        if (myFile.is_open()) {
            unsigned long int objsNum;
           while(getline(myFile, line)){

               //copying line to prob
                //line>>prob;
                prob = line;
               //line = solution
               getline(myFile, line);
               //copying line to sol
               //line>>sol;
               sol = line;
               //getting enter - might be unnecesarry
               getline(myFile, temp);
               //NEED TO USE MAP OF STRING, STRING INSTEAD
               probSol.insert(pair<P, S> (prob, sol));
           }
        }

        myFile.close();
    };
};


#endif //PROJ_2_FILECACHMANAGER_H
