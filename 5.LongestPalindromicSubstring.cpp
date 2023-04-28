class Solution {
  /* Brute force: O(n^3) */   
public:
    string longestPalindrome(string s) {
        pair<int,int> max_range;
        int left = 0, right = s.size()-1, max_size = 0;

        for (int i = 0; i < s.size()-1; i++){
            for (int j = s.size()-1; j > i; j--){
                if (s[i] == s[j]){
                    if (valid_palindrone(s, i, j)){
                        if (j-i+1 > max_size){
                            max_size = j-i+1;
                            max_range.first = i,
                            max_range.second = j;                
                        }
                    }
                }
            }
        }
        
    return s.substr(max_range.first, (max_range.second - max_range.first + 1));
    }

    bool valid_palindrone(string& s, int start, int end){
        int left = start, right = end;
        while (left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
    return true;
    }
};
