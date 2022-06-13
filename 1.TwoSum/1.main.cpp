#include <iostream>
#include <vector>
#include "1.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> map;
        vector<int> answer;
        cout << "p1" << endl;


        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int complement = target - num;
            auto it = map.find(complement);

            //cout << "1.map[" << num << "]: " << map[num] << endl;

            if (it != map.end()){
                //answer.push_back(i);
                //answer.push_back(it->second);
                cout << i << endl;
                cout << it->second << endl;
                cout << "unordered_map size: " << map.bucket_count() << endl;

                
                return answer;
            }
            map[num] = i;
            map[i]
            cout << "2.map[" << num << "]: " << map[num] << endl;

        }
    return answer;
    }
};


int main(){

    vector<int> vec1;

    read("1.txt", vec1);

    Solution s1;

    s1.twoSum(vec1, 9);

    cout << vec1[0] << endl;
    cout << vec1[1] << endl;


return 0;
}