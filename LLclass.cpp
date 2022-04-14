#include <iostream>
using namespace std;

/*
    Linked List with operations implemented through class 
*/

class Node{
    public:
        int data;
        Node* next;

        // default Constructer
        Node(){
            data = 0;
            next = NULL;
        }        // paramter Constructer
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        // main functions
        void insertNodeInFront(int data);
        void deleteNode(unsigned int position);
        void reverseLL();

        // helper function
        void printLL();
        int getListLength();

        // constructor
        LinkedList(){
            head = new Node();
            tail = new Node();
        }

    private:
        Node* head;
        Node* tail;
};

void LinkedList::insertNodeInFront(int newData){
    Node* newNode = new Node(newData);
    newNode->next = head->next;
    head->next = newNode;
}

void LinkedList::deleteNode(unsigned int position){
    // 4 edge cases
    if (head->next == NULL){
        cout << "Linked List is Empty, Nothing to Delete!" << endl;
        return;
    }
    if (position > getListLength()){
        cout << "Position is outside range of LL" << endl;
        return;
    }
    if (position == 0){
        cout << "Can not delete Head" << endl;
        return;
    }
    if (position == 1){
        cout << "deleting only element" << endl;
        head->next = NULL;
        return;
    }
    // edge cases not triggered

    Node* tempTravers1 = head;
    Node* tempTravers2 = head->next;

    int count = 0;
    while(position-- > 1){ // subtracts 1 from position each cycle, while position > 1
        tempTravers1 = tempTravers1->next;
        tempTravers2 = tempTravers2->next;
        count++;
    }
    cout << "Count:" << count << endl;

    tempTravers1->next = tempTravers2->next;

    //delete tempTravers2; // not needed? allocated on stack, dealocates after function ends
    //delete tempTravers1;
}

void LinkedList::reverseLL(){
    // check edge cases
    if (head->next == NULL){
        cout << "Linked List is Empty, Nothing to Reverse!" << endl;
        return;
    }
    if (getListLength() == 1){
        cout << "Can not reverse a single node!" << endl;
        return;
    }

    Node* current = head->next;
    Node* next = current;
    Node* prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
}
int LinkedList::getListLength(){
    int count = 0;
    Node* tempHead = head;
    tempHead = tempHead->next;
    
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }
return count;
}

void LinkedList::printLL(){
    Node* tempHead = head;
    cout << "HEAD" << ":::::::" << tempHead->data << endl;
    tempHead = tempHead->next;
    
    while(tempHead != NULL){
        cout << tempHead << "::" << tempHead->data << endl;
        tempHead = tempHead->next;
    }
}

int main(){
    LinkedList l1;
    cout << "LL length:" << l1.getListLength() << endl;
    l1.insertNodeInFront(1);
    l1.insertNodeInFront(2);
    l1.insertNodeInFront(3);
    l1.insertNodeInFront(4);

    l1.printLL();
    cout << "LL length:" << l1.getListLength() << endl;
    l1.deleteNode(2);
    l1.printLL();
    cout << "LL length:" << l1.getListLength() << endl;

    l1.reverseLL();
    l1.printLL();

return 0;
}

/*
    slav007@Slavs-MacBook-Pro DataStructures % ./LLclass                            
    LL length:0
    HEAD:::::::0
    0x7fe0d9405a80::4
    0x7fe0d9405a70::3
    0x7fe0d9405a60::2
    0x7fe0d9405a50::1
    LL length:4
    Count:1
    HEAD:::::::0
    0x7fe0d9405a80::4
    0x7fe0d9405a60::2
    0x7fe0d9405a50::1
    LL length:3
*/