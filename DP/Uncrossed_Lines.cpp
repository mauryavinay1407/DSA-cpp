// problem: https://leetcode.com/problems/uncrossed-lines

/*
Approach-1: Recursion + Memoization
Time Complexity:    O(M*N)
Space Complexity:   O(M*N)
*/
class Solution {
public:
    int m, n;
    int dp[501][501];
    int findMaxUncrossedLines(vector<int>& nums1, vector<int>& nums2, int i,
                              int j) {
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (nums1[i] == nums2[j])
            return dp[i][j] =
                       1 + findMaxUncrossedLines(nums1, nums2, i + 1, j + 1);
        else
            return dp[i][j] =
                       max(findMaxUncrossedLines(nums1, nums2, i + 1, j),
                           findMaxUncrossedLines(nums1, nums2, i, j + 1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        memset(dp, -1, sizeof(dp));
        return findMaxUncrossedLines(nums1, nums2, 0, 0);
    }
};

/*
Approach-2: Bottom up
Time Complexity:    O(M*N)
Space Complexity:   O(M*N)
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
