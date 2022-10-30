class Solution {
 // Pass by reference
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; preOrder(root, &ans);
    return ans;
    }
    
    void preOrder(TreeNode* root, vector<int>* ans){
        if (root == nullptr) return;
        ans->push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
};


class Solution {
 // Pass by value
public:
    vector<int> preorderTraversal(TreeNode* root) {
    return preOrder(root, {});
    }
    
    vector<int> preOrder(TreeNode* root, vector<int> ans){
        if (root == nullptr) return ans;
        ans.push_back(root->val);
        vector<int> left = preOrder(root->left, ans);        
    return preOrder(root->right, left);
    }
};
