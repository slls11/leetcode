class Solution {
public:
    int max_value(map<char,int>& count){
        int max = 0;
        for (auto iter : count){
            if (iter.second > max) max = iter.second;
        }
    return max;
    }
    
    int characterReplacement(string s, int k) {
        map<char,int> count;
        int length = 0, max_length = 0, left = 0;
        for (int right = 0; right < s.length(); right++){
            count[s[right]]++; 
            length++;
            while (length - max_value(count) > k){
                count[s[left]]--;
                left++; length--;
            }
            if (length > max_length) max_length = length;
        }
    return max_length;
    }
};




class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left = 0, right = -1;
        int length = 0, max_length = 0;
        while (right < int(s.length())){

            if ((length - *max_element(count.begin(), count.end())) <= k){
                if (max_length <= length) max_length = length;

                right++;
                if (right < int(s.length())){
                    count[s[right] - 'A']++;
                    length++;
                }

            }
            else{
                count[s[left] - 'A']--;
                length--;
                left++;
            }
        }
        
    return max_length;
    }
};
