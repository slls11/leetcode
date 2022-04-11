#include <iostream>
#include <vector>
#include <sstream> 
#include <fstream>
#include "1.h"
using namespace std;


/*
takes in .txt file and vector
reads .txt file (colon "," sperated) into vector (by reference &)
*/
void read(string fileName, vector<int> & v1){
    
    ifstream readPipe (fileName.c_str());   ////////////// READ file
    string text;
    if (readPipe.is_open()){
        cout << "File OPENED" << endl;
        cout << "Reading..." << endl;

        int num;

        while (getline  (readPipe,text,',') ){ ///// change ',' to change delimter, '\n' default 

            stringstream IntNum(text);

            IntNum >> num;

            v1.push_back(num);
            
        }

        readPipe.close();
        if (!readPipe.is_open()){
            cout << "File CLOSED" << endl;
        }
    }
    else{
        cout << "File NOT Opened" << endl;
    }

}

