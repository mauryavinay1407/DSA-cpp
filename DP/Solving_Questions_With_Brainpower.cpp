// problem : https://leetcode.com/problems/solving-questions-with-brainpower

/*
Approach - Using Recursion  + Memoization
Time Complexity    :  O(N) 
Space Complexity   :  O(N)
*/

class Solution {
public:
    long long findPoints(vector<vector<int>>& q, int i, vector<long long>& dp) {
        if (i >= q.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long long include = q[i][0] + findPoints(q, q[i][1] + i + 1, dp);
        long long skip = findPoints(q, i + 1, dp);

        return dp[i] = max(include, skip);
    }
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> dp(q.size(), -1);
        return findPoints(q, 0, dp);
    }
};
