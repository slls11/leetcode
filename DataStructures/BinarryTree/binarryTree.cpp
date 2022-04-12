#include <iostream>
using namespace std;

// binary search tree (BST)
// create, delete, insert, traverse tree
// https://www.cprogramming.com/tutorial/lesson18.html

struct Node{
    int data;
    Node *left;
    Node *right;
};

class BinaryTree{
    public:
        BinaryTree(); //constructer
        ~BinaryTree(); //de-constructer

        void insert(int key);
        void delete_tree();
        Node *search(int key);

    private:
        void delete_tree(Node *leaf);
        void insert(int key, Node *leaf);
        Node *search(int key, Node *leaf);
        Node *root;
};

BinaryTree::BinaryTree(){
    root = NULL;
}
BinaryTree::~BinaryTree(){
    delete_tree();
}
void BinaryTree::delete_tree(Node *leaf){
    if (leaf != NULL){
        delete_tree(leaf->left);
        delete_tree(leaf->right);
        delete leaf; // delete keyword destroyes memory block in heap, but not pointer to memory block
    }

}

int main(){
return 0;
}