class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long int left = LONG_MIN; long int right = LONG_MAX;
    return search(root, left, right);
    }
    
    bool search(TreeNode* root, long int left, long int right){
        if (root == nullptr) return true;
        
        if ((root->val >= right || root->val <= left)) return false;
       
        if (root->left != nullptr)
            if (!(search(root->left, left, root->val))) return false;
        
        if (root->right != nullptr)
            if (!(search(root->right, root->val, right))) return false;
        
        return true;
    }
};

