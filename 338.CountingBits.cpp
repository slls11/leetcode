class Solution {
/* Solution with maps, not very fast */
public:
    int find_ones(int num){
        int count = 0;
        for (int j = 16; j > 0; j--){
            if ((num & 1) == 1) count++;
            num = num >> 1;
        }
    return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        ans[0] = 0;
        if (n == 0) return ans;
        ans[1] = 1; 
        if (n == 1) return ans;
        

        unordered_map<int,int> map;
        map[0] = 0; map[1] = 1;

        int closest_pow_two = 1;
        for (int i = 2; i <= n; i++){
            if (i == pow(2, closest_pow_two+1)){
                closest_pow_two++;
                ans[i] = 1;
                continue;
            }

            int rem = i - pow(2, closest_pow_two);

            if (rem == 0){
                ans[i] = 1;
                continue;
            }
            else if (map.find(rem) == map.end()){
                int rem_ones_count = find_ones(rem);
                map[rem] = rem_ones_count;

            }
            ans[i] = map[rem] + 1;
        }
        
    return ans;
    }
};



class Solution {
/* Count all 1, in every num */
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for (u_int i = 0; i <= u_int(n); i++){
            u_int num = i;
            
            for (u_int j = 17; j > 0; j--){
                if((num & 1) == 1) ans[i]++;
                num = num >> 1;
            }

        }
    return ans;
    }
};
