#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        TreeNode* newNode = new TreeNode(val);
        
        if (temp == nullptr){
            root = newNode;
            temp = nullptr;
        }
        
        while(temp != nullptr){
            if (val < temp->val && temp->left != nullptr){
                temp = temp->left;
            }
            else if (val < temp->val && temp->left == nullptr){
                temp->left = newNode;
                temp = nullptr;
            }
            else if (val > temp->val && temp->right != nullptr){
                temp = temp->right;
            }
            else if (val > temp->val && temp->right == nullptr){
                temp->right = newNode;
                temp = nullptr;
            }
            else{
                //cout << "we have a problem" << endl;
                temp = nullptr;
            }
        }
        
    return root;
    }
};


int main(){
    TreeNode t1;

return 0;
}