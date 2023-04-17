class Solution {
    /* O(26 * log(26)) -> O(n * cooldown) */
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<vector<int>> q;
        vector<int> count(26,0);

        for (auto& it : tasks) count[it - 'A']++;
        for (auto& it : count)
            if (it > 0) pq.push(it);

        int time = 0;
        while (!pq.empty() || !q.empty()){
            time++;
            if (!pq.empty()){
                if (pq.top() > 1) q.push({pq.top()-1, time + n});
                pq.pop();
            }
            
            if (!q.empty() && q.front()[1] == time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }
    return time;
    }
};
