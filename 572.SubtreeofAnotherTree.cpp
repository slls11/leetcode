
class Solution {
public:
    bool same = false;
    bool match(TreeNode* root, TreeNode* subRoot){
        if (!root && !subRoot) return true;
        else if  (!root || !subRoot) return false;
        else if (root->val != subRoot->val) return false;

    return (match(root->left, subRoot->left) && match(root->right, subRoot->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        else if (match(root, subRoot)) same = true;
        
        if (!same) isSubtree(root->left, subRoot);
        if (!same) isSubtree(root->right, subRoot);
        
    return same;
    }
};
