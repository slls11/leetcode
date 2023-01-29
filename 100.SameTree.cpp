
class Solution {
public:    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr){
            if (q == nullptr) return true;
            else return false;
        }
        else if (q == nullptr){
            if (p == nullptr) return true;
            else return false;
        }
        else if (p->val != q->val)return false;

    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
