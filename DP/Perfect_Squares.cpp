// problem:  https://leetcode.com/problems/perfect-squares/description

/*
Approach-1 :  Recursion + Memoization
Time Complexity: O(N*sqrt(N))
Space Complexity: O(N)
*/
class Solution {
public:
    int dp[10001];
    int findSquares(int n) {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int count = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            count = min(count, 1 + findSquares(n - i * i));
        }
        return dp[n] = count;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return findSquares(n);
    }
};
/*
Approach-2 :  Bottom-up
Time Complexity: O(N*sqrt(N))
Space Complexity: O(N)
*/
class Solution {
public:
   int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
};
    
