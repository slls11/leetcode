class Solution {
public:
    
    vector<string> add_remove(int left, int right, int n, string str, vector<string>& ans){
        if (left == right && right == n){
            ans.push_back(str);
            return ans;
        }

        if (left < n){
            str.push_back('(');
            add_remove(left+1,right,n,str,ans);
            str.pop_back();
        }

        if (right < left){
            str.push_back(')');
            add_remove(left,right+1,n,str,ans);
            str.pop_back();
        }

    return ans;
    };
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
    return add_remove(0, 0, n, str, ans);
    }
};
