class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        unordered_map <int,int> map1, map2;
        
        for (int i = 0; i < secret.size(); i++){            
            if (secret[i] == guess[i]) bull++;
            else{
                if (map2.find(secret[i]) == map2.end())
                    map1[secret[i]]++;
                else{                    
                    cow++; map2[secret[i]]--;
                    if (map2[secret[i]] == 0) map2.erase(secret[i]); 
                }

                if (map1.find(guess[i]) == map1.end())
                    map2[guess[i]]++;
                else{
                    cow++; map1[guess[i]]--;
                    if (map1[guess[i]] == 0) map1.erase(guess[i]);
                }
            }   
        }
        string strBull = to_string(bull), strCow = to_string(cow);        
        string ans = strBull + "A" + strCow + "B";     
        
    return ans;
    }
};
