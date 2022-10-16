class Solution {
public:
    int firstBadVersion(int n) {
        long int mid = n/2;
        
        while (1){
            bool test1 = isBadVersion(mid); bool test2 = isBadVersion(mid+1);
            if (!test1 && test2) 
                return mid+1;
            else if (!(test1) && !test2)
                mid = (n + mid)/2;
            else if (test1 && test2){
                n = mid;
                mid = mid/2;
            }                
        }
                     
    return -1;    
    }
};
