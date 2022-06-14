class Solution {
public:
    bool isPalindrome(string s) {
        cout << s << endl;
        for (int i = 0; i < s.length(); i++){
            
            if ( (int(s[i]) >= 65 && int(s[i]) <= 90) || (int(s[i]) >= 97 && int(s[i]) <= 122) || (int(s[i]) >= 48 && int(s[i]) <= 57) ){
                
                if ( int(s[i]) >= 65 && int(s[i]) <= 90 ){
                    int asciValue = int(s[i]) + 32;
                    s[i] = char(asciValue);
                }
            }
            else{
                s.erase(i,1);
                i--;
            }
    
        }
        
        if (s.length() == 1){
            return true;
        }
        
        for (int i = 0; i < s.length()/2; i++){
            cout << s[i] << "::" << s[s.length()-1-i] << endl;
            if (s[i] != s[s.length()-1-i]){
                return false;
            }
        }
        
    return true;   
    }
};