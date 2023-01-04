class Solution {
/* this solution only works if it does not time out on the autograder, so really it does not work... */
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<vector<int>> vec_lst;
        vector<string> empty;
        
        for (int i = 0; i < strs.size(); i++){
            string str = strs[i];
            vector<int> vec_str(27,0);
            for (int j = 0; j < str.length(); j++) vec_str[str[j] - 'a']++;
            
            int pos = 0;
            bool new_anagram = true;
            for (int k = 0; k < vec_lst.size(); k++){
                if (vec_str == vec_lst[k]){
                    ans[k].push_back(str);
                    new_anagram = false;
                    pos--;
                }
                pos++;
            }
            if (new_anagram == true && vec_lst.size() > 0){
                vec_lst.push_back(vec_str);
                ans.push_back(empty);
                ans[pos].push_back(str);
            }
            else if (vec_lst.size() == 0){
                vec_lst.push_back(vec_str);
                vector<string> first_word;
                first_word.push_back(str);
                ans.push_back(first_word);
            }
        }
    return ans;
    }
};
