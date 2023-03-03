class Solution {
public:
    void search(TreeNode* root, priority_queue<int>& pq){
        if (root == nullptr) return;

        pq.push(root->val * -1);
        
        search(root->left, pq);
        search(root->right, pq);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        search(root, pq);

        int ans;
        for (int i = 0; i < k; i++){
            ans = pq.top();
            pq.pop();
        }
    return ans*-1;
    }
};
