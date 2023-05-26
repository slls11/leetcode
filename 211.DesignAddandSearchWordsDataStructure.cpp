class WordDictionary {
    /* not using a trie, hashmap instead, would not work for more than 2 dots... */
public:
    void addWord(string word) {set.insert(word);}
    
    bool one_dot(string word, vector<int>& loc){
        for (int i = int('a'); i <= int('z'); i++){
            word[loc[0]] = char(i);
            if (set.find(word) != set.end()) return true;
        }
    return false;
    }

    bool two_dot(string word, vector<int>& loc){
        for (int i = int('a'); i <= int('z'); i++){
            word[loc[0]] = char(i);
            for (int j = int('a'); j <= int('z'); j++){
                word[loc[1]] = char(j);
                if (set.find(word) != set.end()) return true;
            }
        }
    return false;
    }

    bool search(string word) {
        vector<int> loc;
        for (int i = 0; i < word.size(); i++)
            if (word[i] == '.') loc.push_back(i);
        
        if (loc.size() == 1) return one_dot(word, loc);
        if (loc.size() == 2) return two_dot(word, loc);;
        if (set.find(word) != set.end()) return true;

    return false;
    }
private:
    unordered_set<string> set;
};
