class Solution {
  /* Runtime: O(n) */
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;

        int i = 0;
        while (i < temperatures.size()){
            if (s.empty()){
                s.push({temperatures[i],i});
                i++;
            }
            else if (s.top().first < temperatures[i]){
                temperatures[s.top().second] = (i - s.top().second);
                s.pop();
            }
            else if (s.top().first >= temperatures[i]){
                s.push({temperatures[i],i});
                i++;
            }
        }
        
        while (!s.empty()){
            temperatures[s.top().second] = 0;
            s.pop();
        }
        temperatures[temperatures.size()-1] = 0;

    return temperatures;
    }
};
