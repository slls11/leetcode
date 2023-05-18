class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        if (h == piles.size()) return high;

        int mid = high/2;
        while(low < high){
            int smaller_rate_time = count_time(piles, mid-1);
            int mid_rate_time = count_time(piles, mid);

            if (smaller_rate_time > h && mid_rate_time <= h) return mid;
            else if (smaller_rate_time > h && mid_rate_time > h){
                low = mid+1;
                mid = (high+low)/2;
            }
            else{
                high = mid-1;
                mid = (high+low)/2;
            }
        }
        
    return mid;
    }

    int count_time(const vector<int>& piles, int k){
        int time = 0;
        for (int it : piles){
            if (it % k == 0) time += it/k;
            else time += (it/k) + 1;
        }
    return time;
    }
};







class Solution {
public:
    int count_time(int k, vector<int>& piles){
        int i = 0;
        unsigned int total = 0;
        while (i < piles.size()){
            if (k >= piles[i]) total++;
            else {
                total += (piles[i]/k);
                if (!!(piles[i]%k)) total++;
            }
            i++;
        }
    return total;
    }

    int binary_search(int min, int max, int h, vector<int>& piles){
        int low = min, high = max, mid = high/2;
        while(low <= high){
            unsigned int time = count_time(mid,piles);

            if (time == h){ 
                unsigned int left_time = count_time(mid-1,piles);

                if  (left_time > h) return mid;
                else{
                    high = mid - 1;
                    mid = high/2;
                }
            }
            else if (time < h){
                high = mid - 1;
                mid = high/2;
            }
            else if (time > h){
                low = mid + 1;
                mid = (high+low)/2;
            }
        }
    return low;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(), piles.end());
    return binary_search(1,max,h,piles);;
    }
};
