class Solution {
    /* O(n) solution */
public:
    int heightChecker(vector<int>& heights) {
        unordered_map<int,int> map;
        for (auto iter : heights) map[iter]++;
        
        int count = 0, h = 0;
        for (int i = 0; i < heights.size(); i++){
            while (map.find(h) == map.end()) h++;
            if (heights[i] != h) count++;     
          
            map[h]--;
            if (map[h] == 0) map.erase(h);
        }
    return count;
    }
};

class Solution {
      /* O(nlog(n)) solution */
public:
    int heightChecker(vector<int>& heights) {
        priority_queue<int> pq; 
        for (auto iter : heights) pq.push(iter);
        
        int count = 0;
        for (int i = heights.size() - 1; i >= 0; i--){
            if (pq.top() != heights[i]) count++;
            pq.pop();
        }
    return count;
    }
};
