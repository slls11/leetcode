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


/* solution using vectors instead of unorderd_map */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map1 (128,-1), map2(128,-1);
        for (int i = 0; i < s.length(); i++){
            int s_value = int(s[i]), t_value = int(t[i]);
            
            if (map1[s_value] == -1) map1[s_value] = t_value;
            else if (map1[s_value] != t_value) return false;
            
            if (map2[t_value] == -1) map2[t_value] = s_value;
            else if (map2[t_value] != s_value) return false;
        }
    return true;
    }
};
