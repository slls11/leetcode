class Node{
    public:
        Node(){}
        Node(int data){
            val = data;
            next = nullptr;
        }    
    
        int val;
        Node* next;
};

class MinStack {
    public:
        MinStack(){
            head = nullptr;
        }

        void push(int val) {
            Node* newNode = new Node(val);
            
            if (head == nullptr){
                head = newNode;
            }
            else{        
                Node* temp = new Node();
                temp = head;

                head = newNode;
                newNode->next = temp;  
            }
        }

        void pop() {
            if (head != nullptr){
                head = head->next; 
            }
            else{
                cout << "empty, nothing to pop" << endl;
            }
        }

        int top() {
        return head->val;
        }

        int getMin() {
            int min = INT_MAX;
            Node* iter = head;
            
            while (iter != nullptr){
                if (iter->val < min){
                    min = iter->val;
                }
                iter = iter->next;
            }
            
        return min;
        }
    
    private: 
        Node* head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */