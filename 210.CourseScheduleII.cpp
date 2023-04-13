class Solution {
    /* Runtime: O(E + V) */
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> map;
        for (auto& iter : prerequisites) map[iter[0]].push_back(iter[1]);
        
        vector<int> ans;
        unordered_set<int> visted, cycle;

        for (int course = 0; course < numCourses; course++){
            if (!dfs(map, visted, cycle, ans, course)) return {};
        }

    return ans;
    }

    bool dfs(unordered_map<int,vector<int>>& map, unordered_set<int>& visted, 
        unordered_set<int>& cycle, vector<int>& ans, int course){
            if (cycle.find(course) != cycle.end()) return false;
            if (visted.find(course) != visted.end()) return true;

            cycle.insert(course);

            for (auto& iter : map[course]){
                if (!dfs(map, visted, cycle, ans, iter)) return false;
            }

            cycle.erase(course);
            visted.insert(course);
            ans.push_back(course);

    return true;
    }
};
