class Solution {
/* Runtime: O(nlog(n)) */
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> sorted_position;
        for(int i = 0; i < position.size(); i++){
            double time_to_finish = (double) (target - position[i]) / speed[i];
            sorted_position.push_back(make_pair(position[i], time_to_finish));
        }
        sort(sorted_position.begin(), sorted_position.end());

        stack<pair<float,double>> s;
        for (auto& iter : sorted_position) s.push(iter);

        double max_time = 0;
        int fleets = 0;
        while (!s.empty()){
            if (s.top().second > max_time){
                fleets++;
                max_time = s.top().second;
            }
            s.pop();
        }
       
    return fleets;
    }
};
