class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.length() > s.length()) return ans;
        
        vector<int> vecS(26,0), vecP(26,0);
        for (int i = 0; i < p.length(); i++){
            vecS.at(s[i] - 'a')++;
            vecP.at(p[i] - 'a')++;
        }  
        for (int i = p.length() - 1; i < s.length() - 1; i++){
            if (vecS == vecP) ans.push_back(i - p.length() + 1);
            vecS.at(s[i-p.length()+1] - 'a')--;
            vecS.at(s[i+1] - 'a')++;
        }
        if (vecS == vecP) ans.push_back(s.length() - p.length());

    return ans;
    }
};
