#include <iostream>
using namespace std;

/*
    implementaion of queue data structure, command and results at bottom
*/

class Node{
    public:
        int data;
        Node* next;

        // constructers
        Node(){}
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue{
    public:
        // constructers
        Queue(){}
        Queue(int num){
            fillQueue(num);
        }

        // main functions
        void pushNode(int data);
        Node* popNode();
        void fillQueue(int range);
        void numOfPops(int numTimes);

        //helper functions
        bool isEmpty();
        void printQueue();

    private:
        Node* front_ = NULL;
        Node* back_ = NULL;
};

void Queue::fillQueue(int range){
    range++;
    while (range-- > 1){
        pushNode(range);
    }
}

void Queue::numOfPops(int numTimes){
    numTimes++;
    while (numTimes-- > 1){
        popNode();
    }
}

bool Queue::isEmpty(){
    return (front_ == NULL);
}

void Queue::printQueue(){
    Node* tempNode;
    tempNode = back_;

    cout << "---back---" << endl;
    while (tempNode != NULL){
        cout << tempNode->data << endl;
        tempNode = tempNode->next;
    }
    cout << "---front---" << endl;
}

void Queue::pushNode(int data){
    Node* newNode = new Node(data);

    // add to empty queue
    if (isEmpty() == true){
        front_ = newNode;
        back_ = front_;
        return;
    }
    // add to non empty queue
    Node* tempback_ = back_;
    back_ = newNode;
    back_->next = tempback_;
}

Node* Queue::popNode(){
    Node* tempNode = back_;
    Node* nodeToPop = front_;

    // empty queue 
    if (front_ == NULL){
        cout << "Empty queue nothing to pop" << endl;
        return NULL;
    }
    // one Node in Queue
    if (back_ == front_){
        front_ = NULL;
        back_ = NULL;
        return nodeToPop;
    }
    // more than one node in Queue
    while (tempNode->next->next != NULL){ // tempNode gets to second node in front_

        tempNode = tempNode->next;
    }
    tempNode->next = NULL;
    front_ = tempNode;
    return nodeToPop;
}

int main(){
    Queue q1(5);
    q1.printQueue();
    q1.numOfPops(3);
    q1.printQueue();
return 0;
}

/*
    slav007@Slavs-MacBook-Pro Queue % g++ -std=c++14 queue.cpp -o queue
    slav007@Slavs-MacBook-Pro Queue % ./queue 
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
    slav007@Slavs-MacBook-Pro Queue % 
*/