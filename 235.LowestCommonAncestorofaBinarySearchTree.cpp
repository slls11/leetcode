class Solution {
public:
    TreeNode* ans = nullptr;
    void search(TreeNode* root, int min, int max){
        if (root == nullptr) return;
        else if (root->val >= min && root->val <= max){
            ans = root;
            return;
        }
        search(root->left, min, max);
        search(root->right, min, max);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, min(p->val, q->val), max(p->val, q->val));
    return ans;
    }
};



class Solution {
    // messy but working solution, did not know it was a real binary search tree, i.e (left values less, right values greater)
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> lca;
    return search(root, p, q, lca);
    }
    
    TreeNode* search(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> lca){
        if (root == nullptr){
            return nullptr;
        }
        if (root->val == p->val || root->val == q->val){
            int target; int back;
            if (root->val == p->val){
                target = q->val;
                back = p->val;
            }else{
                target = p->val;
                back  = q->val;
            }
            
            while (lca.size() > 0){
                
                if ( search2(lca.back(), target, back) ){
                    
                    return lca.back();
                }
                else{
                    back = lca.back()->val;
                    lca.pop_back();
                }
            }
            return root;    
        }
        
        lca.push_back(root);
        
        TreeNode* left = search(root->left, p, q, lca);
        
        if (left != nullptr){
            return left;
        }
        TreeNode* right = search(root->right, p, q, lca);
        
        if (right != nullptr){
            return right;
        }
        
        
    return nullptr;
    }
    
    bool search2(TreeNode* root, int target, int back){
        if (root == nullptr){
            return false;
        }
        if (root->val == back){
            return false;
        }
        if (root->val == target){
            return true;
        }
        
        return (search2(root->left, target, back) || search2(root->right, target, back));

    }
};
