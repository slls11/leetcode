class Solution {
  /* Runtime: O(n), Space: O(n) */
public:
    int count = 0;
    void search(TreeNode* root, int local_max){
        if (root == nullptr) return;;

        if (root->val >= local_max){
            count++;
            local_max = root->val;
        }

        search(root->left, local_max);
        search(root->right, local_max);

    return;
    }

    int goodNodes(TreeNode* root) {
        search(root, INT_MIN);
    return count;
    }
};
