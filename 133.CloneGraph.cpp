class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
        queue<Node*> q;
        unordered_map<Node*,Node*> map;

        Node* start = new Node(node->val);
        map[node] = start;

        q.push(node);
        while (!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            for (int i = 0; i < curr->neighbors.size(); i++){
                if (map.find(curr->neighbors[i]) == map.end()){
                    map[curr->neighbors[i]] = new Node(curr->neighbors[i]->val);
                    q.push(curr->neighbors[i]);
                }
                map[curr]->neighbors.push_back(map[curr->neighbors[i]]);
            }
        }
    return start;
    }
};
