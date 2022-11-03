class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26,0);
        for (char& iter : s) vec.at(iter - 'a')++;
        for (int i = 0; i < s.length(); i++)
            if (vec[s[i] - 'a'] == 1) return i;  
    return -1;
    }
};


class Solution {
  // using unorderd_map, both solutions are O(2n), so linear runtime, but vector one is faster
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for (auto iter : s){
            if (map.find(iter) == map.end()) map.insert({iter,1});
            else map[iter]++;
        }
        for (int i = 0; i < s.length(); i++)
            if (map[s[i]] == 1) return i;
      
    return -1;
    }
};
