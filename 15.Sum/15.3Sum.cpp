#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>& v1){
        for (auto it : v1){
        cout << it << endl;
    }
}

int main(){
    vector <int> v1 = {-1,0,1,2,-1,-4};
    sort(v1.begin(),v1.end(), less());
    vector <vector<int>> answer;

    for (int s = 0; s < v1.size(); s++){

        int left = s + 1;
        int right = v1.size()-1;
        while (left < right){

            if (s + v1[left] + v1[right] < 0){
                left++;
            }
            else if (s + v1[left] + v1[right] > 0){
                right--;
            }
            else{
                answer.push_back({s, v1[left], v1[right]});
                left++;
                while (v1[left] == v1[left-1] && left < right){
                    left++;
                }
            }

        }

    }

return v1;
}