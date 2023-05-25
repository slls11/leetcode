class Node{
public:
    Node(char user_c){ c = user_c;}
    char c;
    unordered_map<char, Node*> map;
};

class Trie {
public:
    Trie() { head = new Node('*');}
    
    void insert(string word) {
        Node* temp = head;
        for (char c : word){
            if (temp->map.find(c) == temp->map.end()){
                temp->map[c] = new Node(c);
            }
            temp = temp->map[c];
        }
        set.insert(word);
    }
    
    bool search(string word) {
        if (set.find(word) == set.end()) return false;
    return true;
    }
    
    bool startsWith(string prefix) {
        Node* temp = head;
        for (char c : prefix){
            if (temp->map.find(c) == temp->map.end()) return false;
            temp = temp->map[c];
        }
    return true;
    }

private:
    Node* head;
    unordered_set<string> set;
};
