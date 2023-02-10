class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned short count = 0;
        for (unsigned short i = 32; i > 0; i--){
            if (n % 2 == 1) count++;
            n = n >> 1;
        }
    return count;
    }
};
