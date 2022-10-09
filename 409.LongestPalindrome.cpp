class Solution {
public:
    int longestPalindrome(string s) {
        int count[58] = {0};
        for (int i = 0; i < s.length(); i++){
            int charNum = (int (s[i])) - 65;
              count[charNum] += 1;
        }
        
        int length = 0;
        for (int i = 0; i < 58; i++){
            if (count[i] % 2 == 0) length += count[i];
            else if (count[i] % 2 != 0) length += count[i] - 1;        
        }
        
        if (length < s.length()) return length + 1;
        else return length;
    
    return 0;
    }
};
