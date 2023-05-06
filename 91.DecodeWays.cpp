class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        vector<int> vec(s.size() + 1);
        vec[0] = 1;
        vec[1] = 1;

        for (int i = 2; i <= s.size(); i++){
            int ones = stoi(s.substr(i-1,1));
            if (ones != 0){
                vec[i] += vec[i-1];
            }

            int tens = stoi(s.substr(i-2, 2));
            if (tens >= 10 && tens <= 26){
                vec[i] += vec[i-2];
            }
        }
    return vec[s.size()];
    }
};
