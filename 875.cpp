class Solution {
public:
    double totalTime(vector<int>& piles, int rate){
        double time = 0;
        for (int p : piles){
            if ((p/rate) <= 1){
                time = time + 1;
            }
            else{
                time = time + (p/rate);
            }
        }
        cout << "Rate:" << rate << "  " << "Time:" << time << endl;
    return time;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {    
        int min = 1, max = *max_element(piles.begin(), piles.end());
        
        if (h == piles.size()){return max;}
        
        while (min <= max){
            int rate = (min + max)/2;
            cout << "*****" << endl;
            double time = totalTime(piles, rate);
            cout << "----" << endl;
            
            if (time < h && totalTime(piles, rate-1) >= h){ // found min
                cout << "p2" << endl;
                return rate;
            }
            else if (time >= h){
                min = rate + 1;  
            }
            else if (time < h){
                max = rate - 1;
            }
        }

    return -1;    
    }
