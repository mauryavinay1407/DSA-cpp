// problem : https://leetcode.com/problems/power-of-two

/*
Approach - We know that if any number is a power of 2 then it definitely contains only 1 set bit(1)
           so, we for example :       n = 16      n   =     10000
                                                n - 1  =    00001
                                            -----------------------
                                                            00000 = 0

Time Complexity        :  O(1)
Space Complexity       :  O(1)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};
