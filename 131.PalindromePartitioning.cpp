class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        search(s, ans, curr, 0);
    return ans;
    }

    bool is_palindrome(string s, int left, int right){
        while (left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
    return true;
    }

    void search(string s, vector<vector<string>>& ans, vector<string>& curr, int start){
        if (start == s.size()){
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < s.size(); i++){
            if (is_palindrome(s, start, i)){
                string str = s.substr(start, i-start+1);
                curr.push_back(str);
                search(s, ans, curr, i+1);
                curr.pop_back();
            }
        }
    }
};
