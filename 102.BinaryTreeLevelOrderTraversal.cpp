class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        
        if (root == nullptr){return output;}

        queue<TreeNode*> q;
        q.push(root);
        
        while (q.empty() == false){
            int levelSize = q.size();
            vector<int> current;
            
            for (int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                current.push_back(node->val);

                if (node->left != nullptr){
                    q.push(node->left);
                }
                if (node->right != nullptr){
                    q.push(node->right);
                }
                
            }  
            
            output.push_back(current);  
            
        }
        
    return output;
    }
};
