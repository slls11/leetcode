class Solution {
 /* Runtime: O(n) */
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> count(128,0);
        int left = 0, right = 0, max_size = 0;
        while (right < s.length()){
            count[int(s[right])]++;
            
            while (count[int(s[right])] > 1){
                count[int(s[left])]--;
                left++;
            }

            if ((right-left)+1 > max_size) max_size = (right-left)+1;
            right++;   
        }
    return max_size;
    }
};
