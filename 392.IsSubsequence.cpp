class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPos = 0; int count = 0;
        for (int i = 0; i < t.length(); i++){
            if (t[i] == s[sPos]){
                sPos++; count++;
            }
        }
        if (count == s.length()) return true;
        
    return false;
    }
};
