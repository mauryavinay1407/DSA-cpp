// problem:  https://leetcode.com/problems/distinct-subsequences/description/

/*
Approach-1: Recursion + Memoization (very similar to longest common subsequence)
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    int dp[1001][1001];
    int findDistinct(string& s, string& t, int i, int j) {
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j]) {
            int taken = findDistinct(s, t, i + 1, j + 1);
            int skipped = findDistinct(s, t, i + 1, j);
            return dp[i][j] = taken + skipped;
        } else
            return dp[i][j] = findDistinct(s, t, i + 1, j);
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return findDistinct(s, t, 0, 0);
    }
};

/*
Approach-2: Bottom up
Time: O(MN)
Space: O(N)
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<long> dp(N + 1);
        dp[0] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                if (s[i] == t[j]) dp[j + 1] += dp[j];
                if (dp[j + 1] > INT_MAX) dp[j + 1] = 0;
            }
        }
        return dp[N];
    }
};
