lass TimeMap {
  /* Constant lookup, then log(n) for binary search, Runtime: O(log(n)) */
public:
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string binary_search(vector<pair<int,string>>& vec, int timestamp){
        if (!vec.size() || timestamp < vec[0].first) return "";

        int low = 0, high = vec.size()-1;
        int mid = high/2;
        while (low <= high){
            if (vec[mid].first <= timestamp && (mid == vec.size()-1 || vec[mid+1].first > timestamp))
                return vec[mid].second;
            else if (vec[mid].first > timestamp){
                high = mid-1;
                mid = (high+low)/2;
            }
            else{
                low = mid + 1;
                mid = (high+low)/2;
            }
        }

    return vec[mid].second;  
    }
    
    string get(string key, int timestamp) {
    return binary_search(map[key], timestamp);
    }

    unordered_map<string,vector<pair<int,string>>> map;
};
