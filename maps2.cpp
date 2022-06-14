#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map <int,string> map1;
    map1.insert({{1,"hello"},{2,"cat"},{3,"dove"}});
    
    for (pair <int,string> elemt : map1){
        cout << elemt.first << ":" << elemt.second << endl;
    }

    auto result = map1.find(2);

    cout << map1.find(2)->second << endl;
    if (result != map1.end()){
        cout << result->second << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    int a,b,c = 3;

    //cout << a << b << c << endl;

return 0;
}