// problem:  https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

/*
Approach-1: Recursion + Memoization
Time Complexity:   O(N^2)
Space Complexity:   O(N^2)
*/

class Solution {
public:
    int dp[501][501];
    int minStepsToPalindrome(string s, int i, int j) {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = minStepsToPalindrome(s, i + 1, j - 1);
        else {
            return dp[i][j] = 1 + min(minStepsToPalindrome(s, i + 1, j),
                                      minStepsToPalindrome(s, i, j - 1));
        }
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return minStepsToPalindrome(s, 0, s.length() - 1);
    }
};
/*
Approach-2: The blueprint approach( Bottom up)
Time Complexity:   O(N^2)
Space Complexity:   O(N^2)
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //[i,j] shows the steps required from i to j inclusive i.e [0,0]=0
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
