class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0]; int high = prices[0]; 
        int localMax = 0; int totalMax = 0;
        
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] < low){
                low = prices[i];
                high = prices[i];
            }
            if (prices[i] > high) high = prices[i];
            
            localMax = high - low;
            
            if (localMax > totalMax) totalMax = localMax;
        }
    return totalMax;
    }
};
