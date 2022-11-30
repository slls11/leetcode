class Solution {
public:
    int find_k(string s, int start){
        int k = 1; stack<char> stk; string num_str = "";
        if (s[start - 1] - '0' >= 0 && s[start - 1] - '9' <= 0){
            for (int i = start - 1; i >= 0; i--){
                if (s[i] - '0' >= 0 && s[i] - '9' <= 0) stk.push(s[i]);
                else break;
            }
            while (stk.size() > 0){
                num_str += stk.top(); 
                stk.pop();
            }
            k = stoi(num_str);
            return k;
        }
    return k;
    }
  
    string expand(string s, int start, int end){
        int k = find_k(s, start);
        string expanded_str, k_str = to_string(k), inside_str = s.substr(start+1, end-start-1);
        int pos = start - k_str.length();
        for (int i = 0; i < k; i++) expanded_str += inside_str; 
        
        s.erase(pos, end-pos + 1); 
        s.insert(pos, expanded_str);
    return s;
    }
  
    string decodeString(string s) { 
        stack<int> stk;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '[') stk.push(i);
            else if (s[i] == ']'){
                s = expand(s, stk.top(), i);
                i = min (stk.top() - 1, 0);
                stk.pop();
            }
        }
    return s;
    }
};
