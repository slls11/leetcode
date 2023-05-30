class Solution {
  /* Runtime: O(nlog(n)) */
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        if (n > 1) sort(intervals.begin(), intervals.end());
        else return intervals;

        int start = intervals[0][0], end = intervals[0][1];
        int i = 0;
        while (i < n){
            if (end >= intervals[i][0]){
                end = max(end, intervals[i][1]);
            }
            else if (end < intervals[i][0]){
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        ans.push_back({start,end});

    return ans;
    }

};
