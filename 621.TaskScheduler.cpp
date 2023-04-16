class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> map;
        for (auto& iter : tasks){
            map[iter]++;
        }

        priority_queue<pair<int,char>> pq;
        for (auto& iter : map){
            pair<int,char> task = make_pair(iter.second, iter.first);
            pq.push(task);
        }

        int time = 0;
        char prev;
        while (!map.empty()){
            int length = n;
            for (auto& iter : map){
                cout << "prev: " << prev << endl;
                if (iter.first == prev){
                    cout << "-----IDEL" << endl;
                    time += length;
                    continue;
                }

                iter.second--;
                prev = iter.first;
                if (iter.second == 0) map.erase(iter.first);

                length--;
                time++;
                if (length == 0) break; 
            }
            
        }


    return time;
    }
};
