class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visted;
        unordered_map<int,vector<int>> map;
        for (auto& iter : prerequisites) map[iter[0]].push_back(iter[1]);

        for (int course = 0; course < numCourses; course++)
            if (!dfs(map, visted, course)) return false;
        
    return true;
    }

    bool dfs(unordered_map<int,vector<int>>& map, unordered_set<int>& visted, int course){
        if (visted.find(course) != visted.end()) return false;
        if (map[course].empty()) return true;

        visted.insert(course);

        for (int i = 0; i < map[course].size(); i++)
            if (!dfs(map, visted, map[course][i])) return false;
        

        map[course].clear();
        visted.erase(course);

    return true;
    }
};
