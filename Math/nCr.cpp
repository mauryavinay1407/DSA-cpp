// problem   :   https://leetcode.com/problems/total-characters-in-string-after-transformations-i

/*
Approach - Using Pascal triangle
Time Complexity       : O(N*r)
Space Complexity      : O(r)
*/
class Solution {
public:
    const int MOD = 1e9+7;
    int nCr(int n, int r) {
        if (n < r) return 0;
        if (n == r || r == 0) return 1;

        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
            }
        }
        return dp[n][r]%MOD;
    }
};
