class Solution {
    /* cleaner solution */
public:
    bool isAnagram(string s, string t) {
        vector<int> vec_s(27,0), vec_t(27,0);
        for (auto iter : s) vec_s[iter-'a']++;
        for (auto iter : t) vec_t[iter-'a']++;

        if (vec_s == vec_t) return true;
    return false;
    }
};




class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> map1;
        
        if(s.length() != t.length()){
            return false;
        }
        else{
            for (int i = 0; i < s.length(); i++){
                if(map1.find(s[i]) != map1.end()){ // alrady in map, increase count
                    map1.at(s[i]) += 1;
                }
                map1.insert({s[i],1}); // insert chars into map
            }
            for (int i = 0; i < t.length(); i++){
                if (map1.find(t[i]) != map1.end()){ // found match, decrease count
                    map1.at(t[i]) -= 1;
                    
                    if(map1.at(t[i]) < 0){
                        return false;
                
                    }
                }
                else{
                    return false;
                }
                
            }
            
        
            
        }
        
    return true;
    }
};
