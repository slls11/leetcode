class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++){
            expand(s, i, i, count);
            expand(s, i, i+1, count);
        }
    return count;
    }

    void expand(const string& s, int i, int j, int& count){
        while (i > -1 && j < s.size() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
    }
};
