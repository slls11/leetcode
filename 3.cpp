class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map1;
        string strLongest;
        string str;
        
        for (int i = 0; i < s.length(); i++){
            
            //cout << "ON:" << i << ":" << s[i] << endl; 
            
            if (map1.find(s[i]) == map1.end()){ // not in map
                //cout << "inserting into map" << endl;
                map1.insert({s[i],i});
                str+=s[i]; 
            }
            else{ // found repeat
                //cout << "repeat:" << i << ":" << s[i] << endl;
                int deleteBefore = map1.find(s[i])->second +1 ;
                //cout << "delete:" << s.substr(0,deleteBefore) << endl;
                //s.erase(0,deleteBefore);
                i = deleteBefore - 1;
                //cout << "new STR:" << s << endl; 
                str.clear();
                map1.clear();
                //i = -1;
                
            }
                
            if (str.length() > strLongest.length()){ // keeps track of longest string
                strLongest = str;
                //cout << "longest:" << strLongest << endl;
            }
            
        }
    return strLongest.length(); 
    }

};



/*
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map1;
        string strLongest;
        string str;
        
        for (int i = 0; i < s.length(); i++){
            
            if (map1.find(s[i]) == map1.end()){ // not in map
                //cout << "inserting into map" << endl;
                map1.insert({s[i],i});
                str+=s[i]; 
            }
            else{ // found repeat
                //cout << "repeat:" << i << ":" << s[i] << endl;
                int subTract = i - map1.find(s[i])->second;
                //cout << subTract << endl;
                i = i - subTract;
                str.clear();
                map1.clear();
                
            }
                
            if (str.length() > strLongest.length()){ // keeps track of longest string
                strLongest = str;
                //cout << "longest:" << strLongest << endl;
            }
            
        }
    return strLongest.length(); 
    }
*/