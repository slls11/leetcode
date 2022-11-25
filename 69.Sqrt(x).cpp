/* binary search solution, can also be solved without long type by just looking for (x/mid) = mid  */
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int low = 1, high = x/2;
        long mid = high/2;
        
        while (low <= high){
            long sqrt1 = mid*mid, sqrt2 = (mid+1)*(mid+1);
            if (sqrt1 <= x && sqrt2 > x) return mid;
            else if (sqrt1 < x && sqrt2 <= x){
                low = mid + 1;
                mid = (high+low)/2;
            }
            else if (sqrt1 > x){
                high = mid - 1;
                mid = high/2;
            }
        }

    return 0;
    }
};

/* brute force */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        for (long int i = 1; i <= x; i++)
            if (i*i > x) return i - 1;
    return 0;
    }
};
