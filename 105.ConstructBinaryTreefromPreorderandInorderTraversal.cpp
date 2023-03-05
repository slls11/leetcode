class Solution {
  /* Runtime: O(n), i think... */
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorder_index = 0;
        unordered_map<int,int> map_inorder;
        for (int i = 0; i < inorder.size(); i++) map_inorder[inorder[i]] = i;

    return build(preorder, inorder, map_inorder, preorder_index, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& map_inorder, int& preorder_index, int i, int j){
        if (i > j) return nullptr;

        TreeNode* root = new TreeNode(preorder[preorder_index]);
        int pivot = map_inorder[preorder[preorder_index]];
        preorder_index++;

        root->left = build(preorder, inorder, map_inorder, preorder_index, i, pivot-1);
        root->right = build(preorder, inorder, map_inorder, preorder_index, pivot+1, j);

    return root;
    } 
};
