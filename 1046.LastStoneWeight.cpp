class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for (auto iter : stones)
            pq.push(iter);
        
        while (pq.size() > 1){
            int numLarger = pq.top();
                pq.pop();
            int numSmaller = pq.top();
                pq.pop();
            pq.push(numLarger - numSmaller);
        }
        
    return pq.top();
    }
};
