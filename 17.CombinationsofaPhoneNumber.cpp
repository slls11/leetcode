class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() < 1) return {};
        
        vector<string> ans;
        string curr;
        comb(digits, ans, curr, 0);
        
    return ans;
    }

    string get_letters(int num){
        switch(num){
            case 2:return "abc";
            case 3:return "def";
            case 4:return "ghi";
            case 5:return "jkl";
            case 6:return "mno";
            case 7:return "pqrs";
            case 8:return "tuv";
            case 9:return "wxyz";
        }
    return "*";
    }

    void comb(string& digits, vector<string>& ans, string curr, int pos){
        if (curr.size() == digits.length()){
            ans.push_back(curr);
            return;
        }

        string letters = get_letters(digits[pos] - '0');
        for (int i = 0; i < letters.size(); i++){
            curr += (letters[i]);
            comb(digits, ans, curr, pos+1);
            curr.erase(curr.length()-1);
        }
    }
};
