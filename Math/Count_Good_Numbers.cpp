// problem  : https://leetcode.com/problems/count-good-numbers

/*
Approach - Using Binary exponantial power
Time Complexity    : O(logN)
Space Complexity   : O(1)
*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long findPow(long long n, long long p) {
        if (p == 0)
            return 1;
        if (p % 2 == 0) {
            long long half = findPow(n, p / 2);
            return (half * half) % MOD;
        } else {
            return (n * findPow(n, p - 1)) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        return (findPow(5, (n + 1) / 2) * findPow(4, n / 2)) % MOD;
    }
};
