#include <iostream>
#include <vector>
using namespace std;

/*
    makes a tree where first element added is root,                     9 
    elements added after root are split into                        8       10
    less than and decending on the left ,                       5               11
    greater than and accending on the right                 4                       12
    see IMAGE BELOW!                                    3                               15
                                (9,5,3,10,15,8,4,11) 
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

class Tree{ //** tree where elements left of root are decending and right of root are accending, (hollow traingle)
    public:
        Tree(vector<int>& v1);
        void insert(int num);

    private:
        Node* root;
};

void Tree::insert(int num){ // left of root are decending and right of root are accending
    cout << "inserting:" << num << endl;

    Node* newNode = new Node(num);
    Node* temp = root;

    if (root == NULL){
        root = newNode;
        cout << "---ROOT created---" << endl;
        return; // exits after adding root
    }

    while (temp != NULL){
        // left side of tree
        if (num < temp->data && temp->left == NULL){ // left leaf
            temp->left = newNode;
            temp = NULL;
            cout << "---added LEFT leaf---" << endl;
        }
        else if (num < temp->data && num > temp->left->data){ // in between left
            newNode->left = temp->left;
            temp->left = newNode;
            temp = NULL;
            cout << "---added LEFT middle---" << endl;
        }
        else if (num < temp->data && num < temp->left->data){ // keep moving left
            temp = temp->left;
        }
        // right side of tree
        else if (num > temp->data && temp->right == NULL){ // right leaf
            temp->right = newNode;
            temp = NULL;
            cout << "---added RIGHT leaf---" << endl;
        }
        else if (num > temp->data && num < temp->right->data){ // in between right
            newNode->right = temp->right;
            temp->right = newNode;
            temp = NULL;
            cout << "---added RIGHT middle---" << endl;
        }
        else if (num > temp->data && num > temp->right->data){ // keep moving right
            temp = temp->right;
        }

        // in case of error, not part of left or right
        else{
            cout << num << " ERROR, hit unexpected case" << endl;
        }

    }   
    
}

Tree::Tree(vector<int>& v1){
    root = new Node();
    root = NULL;

    for (int i = 0; i < v1.size(); i++){
       insert(v1[i]);
    } 
}

int main(){
    vector<int> v1 = {9,5,3,10,15,8,4,11,12};
    Tree b0(v1);
return 0;
}

/* terminal command and run
slav007@Slavs-MacBook-Pro AccendDecendTree % g++ -std=c++17 accendDeccendTree.cpp -o adt
slav007@Slavs-MacBook-Pro AccendDecendTree % ./adt 
inserting:9
---ROOT created---
inserting:5
---added LEFT leaf---
inserting:3
---added LEFT leaf---
inserting:10
---added RIGHT leaf---
inserting:15
---added RIGHT leaf---
inserting:8
---added LEFT middle---
inserting:4
---added LEFT middle---
inserting:11
---added RIGHT middle---
inserting:12
---added RIGHT middle---
*/
