//
// Created by daniella on 1/6/19.
//

#ifndef PROJ_2_FILECACHMANAGER_H
#define PROJ_2_FILECACHMANAGER_H


#include "CacheManager.h"
#include <map>
#include <fstream>

using namespace std;

template<class P, class S>

class FileCacheManager : public CacheManager<P, S> {
    map<P, S> probSol;
    string fileName;

public:

    FileCacheManager(const string fName) {
        fileName = fName;
        creatMap();
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
                return it->second;
            }
        }
        throw "no saved solution for that problem";
    };

    virtual void saveSolution(P p, S s) {
        probSol.insert(pair<P, S>(p, s));
    };

    void creatMap() {
        ifstream myFile(fileName);
        if (myFile.is_open()) {
            unsigned long int objsNum;
            //NEED TO CHECK IF THIS MAKES THR IFSTREAM GO A ROW BELOW
            myFile >> objsNum;
            //skipping two because every two rows theres a problem and a solution
            for (unsigned long int i = 0; i < objsNum; i+=2) {
                P prob;
                S sol;
                //ALSO HERE- NEED TO CHECK IF THIS MAKES THR IFSTREAM GO A ROW BELOW
                myFile>>prob;
                myFile>>sol;
                probSol.insert(pair<P, S> (prob, sol));
            }
        }

        myFile.close();
    };

    //need to call this when the user writes "end"
    void saveMapInFile() {
        ofstream myFile(fileName);
        if (myFile.is_open()) {
            //saving number of problems and solutions to file
            myFile << probSol.size() << endl;
            for (typename::map<P, S>::iterator it = probSol.begin(); it != probSol.end(); ++it) {
                myFile << it->first << endl << it->second << endl;
            }
        }

        myFile.close();
    };
};


#endif //PROJ_2_FILECACHMANAGER_H
