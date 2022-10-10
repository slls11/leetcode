class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        if (nums.size() == 1){
            if (nums[0] == 0){

            }
            else{    
                return -1;  
            }
        }

        
        double total = 0;
        for (int i = 0; i < nums.size(); i++){
            total += nums[i];
        }
        cout << total << endl;
        
        int left = 0;        
        total = total - nums[0];
        if (left == total){
                return 0;
        }
        for(int i = 1; i < nums.size(); i++){


            left = left + nums[i-1];
            total = total - nums[i];
            cout << nums[i] << endl;
            
            if (left == total){
                return i;
            }
        }

    return -1;
    }
};
