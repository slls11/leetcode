class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount+1, amount+1);
        count[0] = 0;

        for (int num = 1; num <= amount; num++){
            for (int denom = 0; denom < coins.size(); denom++){
                if (num - coins[denom] < 0) continue;
                count[num] = min(count[num], 1 + count[num - coins[denom]]);
            }
        }

        if (count[amount] == amount+1) return -1;
    
    return count[amount];
    }
};
