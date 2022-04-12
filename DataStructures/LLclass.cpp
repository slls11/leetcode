#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // default Constructer
        Node(){
            data = 0; 
            next = NULL;
        }
        // paramter Constructer
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        void insertNodeFront(int data);

        void printLL();

        LinkedList(){
            head = new Node();
            tail = new Node();
        }

    private:
        Node* head;
        Node* tail;
};

void LinkedList::insertNodeFront(int newData){
    Node* newNode = new Node(newData);
    newNode->next = head->next;
    head->next = newNode;
}

void LinkedList::printLL(){
    Node* tempHead = head;
    cout << "HEAD" << "::" << tempHead->data << endl;
    tempHead = tempHead->next;
    
    while(tempHead != NULL){
        cout << tempHead << "::" << tempHead->data << endl;
        tempHead = tempHead->next;
    }
}

int main(){
    LinkedList l1;
    l1.insertNodeFront(1);
    l1.insertNodeFront(2);
    l1.insertNodeFront(3);
    l1.printLL();
return 0;
}