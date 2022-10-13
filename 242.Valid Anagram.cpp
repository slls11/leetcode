class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int count[28] = {0};
        for (int i = 0; i < s.size(); i++){
            int svalue = int (s[i]) - 97;
            count[svalue]++;
            int tvalue = int (t[i]) - 97;
            count[tvalue]--;
        }    
  
        for (auto iter : count)
            if (!!iter) return false;
        
    return true;
    }
};
