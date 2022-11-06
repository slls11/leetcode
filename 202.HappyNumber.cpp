class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> map;
        while(1){
            string str_num = to_string(n); n = 0;
            for (int i = 0; i < str_num.size(); i++){
                int num = (str_num[i] - '0');
                n += (num * num);
            }            
            if (n == 1) return true;
            map[n]++;
            if (map[n] > 1) return false;
        }
    return 0;
    }
};
