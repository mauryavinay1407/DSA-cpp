// problem : https://leetcode.com/problems/power-of-three

/*
Approach-1 : Iteratively dividing by 3
Time Complexity      :  O(log₃ N)
Space Complexity     :  O(1)
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

/*
Approach-2 : Recursively dividing by 3
Time Complexity      :  O(log₃ N)
Space Complexity     :  O(log₃ N) (recursive call stack)
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        return (n % 3 == 0) && isPowerOfThree(n / 3);
    }
};

/*
Approach-3 : Checking divisibility with the largest power of 3 within int range
Time Complexity      :  O(1)
Space Complexity     :  O(1)
Note: 3^19 = 1162261467 is the largest power of 3 that fits in a signed 32-bit integer.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

/*
Approach-4 : Using logarithms (checking if log₃(n) is an integer)
Time Complexity      :  O(1)
Space Complexity     :  O(1)
*/
#include <cmath>
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        double logValue = log10(n) / log10(3);
        return logValue == (int)logValue;
    }
};
