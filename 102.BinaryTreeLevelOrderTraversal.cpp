class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        vector<TreeNode*> temp {root};
        vector<TreeNode*> new_level;
        while (1){
            vector<int> curr_vec;

            for (int i = 0; i < temp.size(); i++){
                TreeNode* node = temp[i];
                curr_vec.push_back(node->val);
                if (node->left != nullptr) new_level.push_back(node->left);
                if (node->right != nullptr) new_level.push_back(node->right);
            }

            ans.push_back(curr_vec);
            temp = new_level;
            new_level.clear();

            if (temp.size() == 0) break;
        }

    return ans;
    }
};



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
