class Solution {
public:
    int climbStairs(int n) {
        int one = 1; int two = 0; 
        int temp = 0;
        
        for (int i = n - 1; i > 0; i--){
            temp = one;
            one = one + two;
            two = temp;
        }
        
    return one+two;
    }
};
