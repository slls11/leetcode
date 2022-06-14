#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

void printVector(vector<int> const& v1){
    cout << &v1 << endl;
    //cout << &*v1<<endl;
    cout << "Printing v1:" << &v1 << endl;
    for(auto i : v1){
        cout << i << endl;
    }
    cout << "\n";
}

void printArray(const int (&arr1)[4]){
    cout << "arr1Print:" << arr1 << endl;

    cout << "Printing arr1:" << arr1 << endl;
    for(auto i : arr1){
        cout << i << endl;
    }
    cout << "\n";
}


void printInt(int & num){
    cout << "printInt:" << num << endl;
    cout << &num << endl;
}

void printVector2(vector<int>* v1){
    cout << "PrintingVEctor2" << endl;
    for(auto i : *v1){
        cout << i << endl;
    }
    cout << "\n";
}

void printMap(unordered_map <int,string>& map1){
    cout << "printMap:" << &map1 << endl;
    cout << "PrintingMap" << endl;
    for(auto const& i : map1){
        cout << i.first << ":" << i.second << endl;
    }
    cout << "\n";
}

void printMap2(unordered_map <int,string>& map1){
    cout << "printMap2:" << &map1 << endl;
    cout << "PrintingMap2" << endl;
    for(auto iter = map1.begin(); iter != map1.end(); iter++){
        cout << iter->first << ":" << iter->second << endl;
    }
    cout << "\n";
}


int main(){
    vector <int> v1 = {2,5,8,89,43};
    cout << &v1 << endl;
    printVector(v1);

    int arr1[] = {12,4,5,6};
    cout << "arr1:" << arr1 << endl;
    printArray(arr1);

    int num = MAX_INPUT;
    cout << &num << endl;
    cout << *&num << endl;
    printInt(num);
    printVector2(&v1);

    unordered_map <int,string> map1 = {{1,"hello"},{4,"dkfsf"},{7,"this is a stirng"}};
    cout << "map1     :" << &map1 << endl;
    printMap(map1);
    printMap2(map1);
    
return 0;
}