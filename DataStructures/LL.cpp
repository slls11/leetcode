#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void push(Node* headRef, int newData){
    Node* newItem = new Node();
    newItem->data = newData;
    newItem->next = headRef->next;
    headRef->next = newItem;
}

// only use if Node* head = new Node();
void pushWithDoublePtr(Node** headRef, int newData){
    Node* newItem = new Node();
    newItem->data = newData;
    newItem->next = (*headRef);
    (*headRef) = newItem;
}

void printLL(Node* head){
    head = head->next;
    while(head != NULL){
        cout << head << "::" << head->data << endl;
        head = head->next;
    }
    cout << "---END---\n" << endl;
}

void simpleLL(Node* headRef){

    cout << "&headRef:" << &headRef << endl;
    cout << "headRef :" << headRef << endl;
    // create individual nodes
    Node* one = new Node();
    Node* two = new Node();
    Node* three = new Node();

    // assign values to nodes
    one->data = 1;
    two->data = 2;
    three->data = 3;

    // connect Nodes
    cout << "p0\n";
    headRef->next = one;
    cout << "p1\n";
    one->next = two;
    two->next = three;
    three->next = NULL;

    cout << "After connection: \n";
    cout << "headRef->data :" << headRef->data << endl;
    cout << "headRef->next :" << headRef->next << endl;
    cout << "LL created\n";

}

// create a singley LL
int main(){
    // create individual nodes
    Node* head = new Node();


    // testing values
    cout << "&head:" << &head << endl;
    cout << "head :" << head << endl;
    // cout << "*head :" << *head << endl; // error
    //cout << "head->data :" << head->data << endl;
    //cout << "head->next :" << head->next << endl;

    // create simple LL
    simpleLL(head);
    // print LL
    printLL(head);

    // testing values
    //cout << "&head:" << &head << endl;
    //cout << "head :" << head << endl;
    // cout << "*head :" << *head << endl; // error
    //cout << "head->data :" << head->data << endl;
    //cout << "head->next :" << head->next << endl;

    // push node to front of LL
    push(head, 99);
    printLL(head);
    push(head, 88);
    printLL(head);
    //pushWithDoublePtr(&head,77);
    //printLL(head);


return 0;
}