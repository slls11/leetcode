class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> dist_all;

        for (auto& cords : points){
            pair<int, pair<int,int>> dist;
            dist.first = find_dist(cords[0], cords[1]);
            dist.second.first = cords[0];
            dist.second.second = cords[1];
            dist_all.push(dist);
        }

        vector<vector<int>> ans;
        while (k > 0){
            vector<int> temp = {dist_all.top().second.first, dist_all.top().second.second};
            ans.push_back(temp);
            dist_all.pop();
            k--;
        }

    return ans;
    }

    int find_dist(int x1, int y1){
    return (pow(x1-0, 2) + pow(y1-0, 2)) * -1;
    }
};
