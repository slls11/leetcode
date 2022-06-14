#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map <char,int> map1 = {{'c',3},{'u',8},{'p',9}};

    cout << map1.at('c') << endl;
    map1.at('c') += 1;
    cout << map1.at('c') << endl;

    cout << INT_MAX << endl;

return 0;
}