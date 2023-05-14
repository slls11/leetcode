class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (auto& str : wordDict) set.insert(str);

        vector<bool> dp(s.size()+1, false);
        dp[0] = true;

        for (int j = 0; j < s.size(); j++){
            for (int i = j; i > -1; i--){
                string word = s.substr(i, j-i+1);
                if (set.find(word) != set.end() && dp[i]){
                    dp[j+1] = true;
                    break;
                }
            }
        }
        
    return dp[s.size()];
    }
};
