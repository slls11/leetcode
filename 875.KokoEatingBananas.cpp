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
