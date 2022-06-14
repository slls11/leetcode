#include <iostream>
#include <fstream>
using namespace std;

void read(string fileName){

    ifstream readPipe (fileName.c_str());
    string str;

    while (getline (readPipe,str)){
        cout << str << endl;
    }

    readPipe.close();
    
}

int main(int argc, char* argv[]){
    cout << "number of arguments:" << argc << endl;
    for (int i = 0; i < argc; i++){
        cout << "argument:" << i << ":" << argv[i] << endl;
    }
    string str = "test.txt";

    read(argv[1]);

return 0;
};