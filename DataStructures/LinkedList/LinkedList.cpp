#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};


void traverseLL(Node *n){
    while(n != NULL){
        cout << n->data << endl;
        n = n->next;
    }
}
void insert(Node **, int position){
    for(int i = 0; i < n; i++){
        n = n->next;
    }
    Node * newNode = new Node;
    

    cout << n->data << endl;
}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocared blocks in heap
    head = new Node();
    second = new Node();
    third = new Node();


    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    traverseLL(head);

    // insert a node

    insert(head,2)
    

return 0;
}