#include <iostream>
#include <vector>
using namespace std;

/*
    insertion into binary search tree (BST)
*/

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(){
            //cout << "created DEFAULT Node" << endl;
        }
        Node(int num){
            //cout << "created NUM Node" << endl;
            data = num;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{ 
    public:
        BST(){
            root = new Node();
            root = NULL;
        }

        void insertNodeBST(int num);
        void insertAll(vector<int>& v1);
        void check();

    private:
        Node* root;
};

void BST::insertNodeBST(int num){// all the magic happens in this function
    cout << "insertNodeBST:" << num << endl;

    Node* newNode = new Node(num);
    Node* temp = root;

    if (root == NULL){
        root = newNode;
        cout << "---ROOT created---" << endl;
        return; // exits after adding root
    }

    while (temp != NULL){
        if (num < temp->data && temp->left != NULL){
            temp = temp->left;
        }
        else if (num < temp->data && temp->left == NULL){
            temp->left = newNode;
            temp = NULL;
        }
        else if (num > temp->data && temp->right != NULL){
            temp = temp->right;
        }
        else if (num > temp->data && temp->right == NULL){
            temp->right = newNode;
            temp = NULL;
        }
        else{
            cout << "we have a problem" << endl;
            temp = NULL;
        }
    }
    cout << "---Node Added---" << endl;

}

void BST::insertAll(vector<int>& v1){
    for (int i = 0; i < v1.size(); i++){
        insertNodeBST(v1[i]);
    }
}

void BST::check(){
    // add numbers to site to check https://www.cs.usfca.edu/~galles/visualization/BST.html 
    cout << "Check" << endl;
    cout << "root->data:              " << root->data << endl;//8
    cout << "root->left->data:        " << root->left->data << endl;//3
    cout << "root->left->left->data:  " << root->left->left->data << endl;//1
    cout << "root->left->right->data  " << root->left->right->data << endl;//6
    cout << "root->right->data:       " << root->right->data << endl;//10
    cout << "root->right->left->data: " << root->right->left->data << endl;//9
    cout << "root->right->right->data:" << root->right->right->data << endl;//11
}

int main(){
    vector<int> v1 = {8,3,1,6,10,9,11};// no identical numbers allowed!
    BST b1;
    b1.insertAll(v1);
    b1.check();
return 0;
}

/* termnial and run
slav007@Slavs-MacBook-Pro BinarySearchTree % g++ -std=c++17 bst.cpp -o bst
slav007@Slavs-MacBook-Pro BinarySearchTree % ./bst
insertNodeBST:8
---ROOT created---
insertNodeBST:3
---Node Added---
insertNodeBST:1
---Node Added---
insertNodeBST:6
---Node Added---
insertNodeBST:10
---Node Added---
insertNodeBST:9
---Node Added---
insertNodeBST:11
---Node Added---
Check
root->data:              8
root->left->data:        3
root->left->left->data:  1
root->left->right->data  6
root->right->data:       10
root->right->left->data: 9
root->right->right->data:11
*/

/* extra code

while (temp->left != NULL || temp->right != NULL){
        if (num < temp->data){
            temp = temp->left;
        }
        else if (num > temp->data){
            temp = temp->right;
        } 
    }

    if (num < temp->data){
        temp->left = newNode;
    }
    else{
        temp->right = newNode;
    }
    cout << "---Added Node---" << endl;


void BST::printBST(){
    Node* tempLeft = root;
    Node* tempRight = root;
    
    int i = 1;
    cout << "level 0:" << root->data << endl;
    while (tempLeft != NULL || tempRight != NULL){
        cout << "level:" << i << "      " << tempRight->data
        cout << tempRight->data << endl;
        tempLeft = tempLeft->left;

    }
}

*/