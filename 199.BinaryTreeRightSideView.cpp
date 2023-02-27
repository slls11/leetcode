class Solution {
public:
    vector<int> levels;
    int count = 0;
    void right(TreeNode* root){
        if (root == nullptr) {
            count++;
            return;
        }

        count++;
        if (count > levels.size())levels.push_back(root->val);
        
        right(root->right);
        count--;
        right(root->left);
        count--;
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return levels;
        right(root);
    return levels;
    }
};
