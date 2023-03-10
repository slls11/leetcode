class Solution {
/* Runtime: O(n) */ 
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s2_window_count(26,0);
        vector<int> s1_count(26,0);
        for (char& iter : s1) s1_count[iter - 'a']++;

        int left = 0, right = s1.length()-1;
        for (int i = 0; i <= right; i++) s2_window_count[s2[i] - 'a']++;


        while (right < s2.length()){
            if (s2_window_count == s1_count) return true;

            s2_window_count[s2[left] - 'a']--;
            left++;
            
            right++;
            if (right < s2.length()) s2_window_count[s2[right] - 'a']++;
        }

    return false;
    }
};



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(27,0);
        for (auto& iter : s1) count[iter - 'a']++;

        int left = 0, right = 0, total = 0;
        while (right < s2.length()){
            if (count[s2[right] - 'a'] > 0){
                count[s2[right] - 'a']--;
                right++;
                total++;
            }
            else{
                if (left < right){
                    count[s2[left] - 'a']++;
                    left++;
                    total--;
                }
                else{
                    left++;
                    right++;
                    total = 0;
                }
            }
            if (total == s1.length()) return true;
        }
    return false;
    }
};
