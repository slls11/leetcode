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

class Stack{
    public:
        // main functions
        void pushNode(int data);
        void popNode(unsigned int position);

        // helper function
        void printLL();
        int getListLength();

        // constructor
        Stack(){
            head = new Node();
            tail = new Node();
        }

    private:
        Node* head;
        Node* tail;
};

void Stack::pushNode(int newData){
    Node* newNode = new Node(newData);
    newNode->next = head->next;
    head->next = newNode;
}

// can be used as pop in a stack
void Stack::popNode(unsigned int position){
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
        head->next = head->next->next;
        cout << "Poping top of stack" << endl;
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

int Stack::getListLength(){
    int count = 0;
    Node* tempHead = head;
    tempHead = tempHead->next;
    
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }
return count;
}

void Stack::printLL(){
    Node* tempHead = head;
    cout << "-----Top----:" << endl;
    tempHead = tempHead->next;

    while(tempHead != NULL){
        cout << tempHead << "::" << tempHead->data << endl;
        tempHead = tempHead->next;
    }
}

int main(){
    Stack l1;

    l1.pushNode(1);
    l1.pushNode(2);
    l1.pushNode(3);
    l1.pushNode(4);
    l1.pushNode(5);

    l1.printLL();
    cout << "LL length:" << l1.getListLength() << endl;
    l1.popNode(1);
    l1.printLL();
    cout << "LL length:" << l1.getListLength() << endl;

return 0;
}






/*
    slav007@Slavs-MacBook-Pro Stack % g++ -std=c++14 Stack.cpp -o Stack
    slav007@Slavs-MacBook-Pro Stack % ./Stack 
    ---back---
    1
    2
    3
    4
    5
    ---front---
    ---back---
    1
    2
    ---front---
    slav007@Slavs-MacBook-Pro Stack % 
*/