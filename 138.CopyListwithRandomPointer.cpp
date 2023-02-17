class Solution {
    /* Runtime: O(n) */
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,short> map;
        Node* temp_head = head;
        short index = 0;
        while (temp_head != nullptr){
            map[temp_head] = index;
            index++;
            temp_head = temp_head->next; 
        }
        map[nullptr] = index;

        vector<short> indices;
        temp_head = head;
        while (temp_head != nullptr){
            indices.push_back(map[temp_head->random]);
            temp_head = temp_head->next;
        }

        vector<Node*> node_address;
        temp_head = head;
        while (temp_head != nullptr){
            Node* new_node = new Node(temp_head->val);
            node_address.push_back(new_node);
            temp_head = temp_head->next;
        }
        node_address.push_back(nullptr);

        for (short i = 0; i < node_address.size()-1; i++){
            node_address[i]->next = node_address[i+1];
            node_address[i]->random = node_address[indices[i]];
        }

    return node_address[0];
    }
};



class Solution {
  /* Runtime: O(n^2) */ 
public:
    int find_index(Node* head, Node* target){
        if (target == NULL) return -1;
        
        short count = 0;        
        Node* temp = head; 
        while (temp != nullptr){
            if (target == temp) return count;
            count++; temp = temp->next;
        }
    return -2;    
    }

    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        vector<short> node_index;
        node_index.push_back(find_index(head, head->random)); // first element

        Node* new_head = new Node(head->val);
        Node* temp = new_head;
        Node* temp_head = head->next;
        vector<Node*> node_address;

        while (temp_head != nullptr){
            node_index.push_back(find_index(head, temp_head->random));
            node_address.push_back(temp);

            Node* new_node = new Node(temp_head->val);
            temp->next = new_node;
            temp = new_node;
            temp_head = temp_head->next;
        }
        node_address.push_back(temp);

        for (short i = 0; i < node_index.size(); i++){
            if (node_index[i] == -1) 
                node_address[i]->random = nullptr;
            else 
                node_address[i]->random = node_address[node_index[i]];
        }

    return new_head;
    }
};
