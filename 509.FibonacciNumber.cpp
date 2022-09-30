class Solution {
public:
    int fib(int n) {
        if (n == 0){
            return 0;
        }
        else if (n == 1){
            return 1;
        }
        
        int one = 1; int two = 0;
        while (n > 2){
            int temp = one;
            one = one + two;
            two = temp;
            n--;
        }
        
    return one+two;
    }
};
