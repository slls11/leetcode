class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int pops = 0, pushs = 0;
        for (auto& iter : s){
            if (iter == '(' || iter == '{' || iter == '[') {
                stk.push(iter);
                pushs++;
            }
            else if (iter == ')'){
                pops++;
                if (!stk.empty() && stk.top() == '(') stk.pop();
            }
            else if (iter == '}'){
                pops++;
                if (!stk.empty() && stk.top() == '{') stk.pop();
            }
            else if (iter == ']'){
                pops++;
                if (!stk.empty() && stk.top() == '[') stk.pop();
            }
        }
        if (pops != pushs) return false;
        else if (!stk.empty()) return false;

    return true;
    }
};
