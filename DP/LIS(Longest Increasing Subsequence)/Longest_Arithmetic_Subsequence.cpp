// problem:  https://leetcode.com/problems/longest-arithmetic-subsequence/description/

/*
Approach-1: Recursion + Memoization (same as lc 1218)
Time Complexity:    O(N^2)
Space Complexity:   O(N*1000) ~ O(N)
*/
class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>& nums, int diff, int j) {
        if (dp[j][diff + 500] != -1)
            return dp[j][diff + 500];
        int result = 0;
        for (int idx = j + 1; idx < nums.size(); idx++) {
            if ((nums[idx] - nums[j]) == diff)
                result = max(result, 1 + solve(nums, diff, idx));
        }
        return dp[j][diff + 500] = result;
    }
    int longestArithSeqLength(vector<int>& nums) {
        if (nums.size() <= 2)
            return (int)nums.size();
        int result = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int diff = nums[j] - nums[i];
                result = max(result, 2 + solve(nums, diff, j));
            }
        }
        return result;
    }
};

/*
Approach-2: Bottom up (same as lc 300)
Time Complexity:    O(N^2)
Space Complexity:   O(N*1000) ~ O(N)
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int result=0;
        vector<vector<int>> dp(n,vector<int>(1001,1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                result =  max(result,dp[i][diff]);
            }
        }
        return result;
    }
};
