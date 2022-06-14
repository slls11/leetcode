#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    
    public:
        void printMap(vector <vector<int>>& answer){
            cout << answer.size() << endl;
            vector <int> temp;

            for (vector <vector<int>>:: iterator it = answer.begin(); it != answer.end(); it++){
               
                for (auto iter : *it){
                    cout << iter << ",";
                }
                cout << "|";
            } 
            
        }
    
        vector<vector<int>> threeSum(vector<int>& nums) {
            unordered_map <int,int> map;
            vector <vector<int>> answer;

            for(int i = 0; i < nums.size(); i++){
                map.insert({nums[i],i});
            }
            cout << "p1" << endl;
            for (int i = 0; i < nums.size()-2; i++){

                for (int j = i+1; j < nums.size()-1; j++){

                    int comp = -1 * (nums[i] + nums[j]);

                    if ( map.find(comp) != map.end() ){
                        if (map.find(comp)->first != nums[i] && map.find(comp)->first != nums[i] && nums[i] != nums[j]){
                            answer.push_back({map.find(comp)->first,nums[i],nums[j]});
                        }
                    }
                }
            }
            
            printMap(answer);

        return answer;
        }
};

int main(){
    Solution s1;
    vector <int> v1 = {-1,0,1,2,-1,-4};
    s1.threeSum(v1);

    cout << max(9,8) << endl;
return 0;
};