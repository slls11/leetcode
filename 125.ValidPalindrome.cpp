class Solution {
    /* cleaner solution */
public:
    bool isPalindrome(string s) {
        string str;
        for (auto& iter : s){
            if (int(iter) >= 65 && int(iter) <= 90 || int(iter) >= 97 && int(iter) <= 122 || int(iter) >= 48 && int(iter) <= 57)
            str += iter;
        }
        for (auto& iter : str){
            if (int(iter) >= 65 && int(iter) <= 90) iter = iter + 32;
        }

        int left = 0, right = str.size()-1;
        while (left < right){
            if (str[left] != str[right]) return false;
            left++; right--;
        }
    return true;
    }
};


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
