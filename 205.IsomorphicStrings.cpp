class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> map1, map2;
        for (int i = 0; i < s.length(); i++){
            if (map1.find(s[i]) == map1.end()){
                map1[s[i]] = t[i];
                if (map2.find(t[i]) != map2.end()) 
                    return false; 
                else
                    map2[t[i]] = s[i];
            }
            else if (map1.find(s[i]) != map1.end()){
                if (map2.find(t[i]) == map2.end()) 
                    return false;
                else if (map1.find(s[i])->first != map2.find(t[i])->second) 
                    return false; 
            }
            
        }
        
    return true;
    }
};
