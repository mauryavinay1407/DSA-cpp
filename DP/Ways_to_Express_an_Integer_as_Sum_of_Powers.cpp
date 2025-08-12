// problem   :  https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers


/*
Approach - using recursion + memoization
Time Complexity         :  O(N^2)
Space Complexity        :  O(N^2)
*/
class Solution {
public:
    const int MOD = 1e9 + 7;
    int find(int i, int n, int x, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        int curr = pow(i, x);
        if (curr > n) {
            return 0;
        }
        if (dp[n][i] != -1) {
            return dp[n][i];
        }
        int taken = find(i + 1, n - curr, x, dp);
        int skip = find(i + 1, n, x, dp);
        return dp[n][i] = (taken + skip) % MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return find(1, n, x, dp);
    }
};
