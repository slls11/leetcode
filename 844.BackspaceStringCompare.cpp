class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> newS;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '#'){
                if (i != 0 && newS.size() > 0) newS.pop();
            }
            else newS.push(s[i]);
        }
        
        stack <char> newT;
        for (int i = 0; i < t.length(); i++){
            if (t[i] == '#'){
                if (i != 0 && newT.size() > 0) newT.pop();
            }
            else newT.push(t[i]);
        }
        
        if (newS.size() != newT.size()) return false;

        int size = newS.size();
        for (int i = 1; i <= size; i++){
            if (newS.top() != newT.top()) return false;
            newS.pop(); 
            newT.pop();
        }
        
    return true;    
    }
};
