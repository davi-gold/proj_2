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
                string temp = it->second+"\r\n";
                return temp;
            }
        }
        throw "no saved solution for that problem";
    };

    virtual void saveSolution(P p, S s) {
        probSol.insert(pair<P, S>(p, s));
        string prob = p;
        string sol = s;
        sol = sol.substr(0, sol.size()-1);
        ofstream myFile(fileName, ios::app);

        //want to append the file
        if(myFile.is_open()){
            myFile << prob << endl << sol << endl;
            myFile.close();
        }
    };

    void createMap() {
        ifstream myFile(fileName);
        string line;
        P prob;
        S sol;
        string temp;
        if (myFile.is_open()) {
            unsigned long int objsNum;
            //NEED TO CHECK IF THIS MAKES THR IFSTREAM GO A ROW BELOW
            //myFile >> objsNum;
            //skipping two because every two rows theres a problem and a solution
           /* for (unsigned long int i = 0; i < SIZE OF FILE; i+=2) {

                //ALSO HERE- NEED TO CHECK IF THIS MAKES THR IFSTREAM GO A ROW BELOW
                myFile>>prob;
               myFile>>sol;
            }*/

           //line = problem
           while(getline(myFile, line)){

               //copying line to prob
                //line>>prob;
                prob = line;
               //line = solution
               getline(myFile, line);
               //copying line to sol
               //line>>sol;
               sol = line;
               getline(myFile, temp);
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
