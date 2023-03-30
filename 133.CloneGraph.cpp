class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*,Node*> map;
        queue<Node*> q;

        map[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();

            for (auto& iter : curr->neighbors){
                if (map.find(iter) == map.end()){
                    map[iter] = new Node(iter->val);
                    q.push(iter);
                }
                map[iter]->neighbors.push_back(map[curr]);
            }
        }
    return map[node];
    }
};
