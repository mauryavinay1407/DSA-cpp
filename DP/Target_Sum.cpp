// problem:  https://leetcode.com/problems/target-sum/description/

/*
Approach- Recusrion + Memoization
Time Complexity: O(N)
Space Complexity: O(N) 
*/

class Solution {
public:
    int dp[1001][2001];
    int findTarget(vector<int>& nums, int i, int sum, int target) {
        if (i >= nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        if (dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];

        return dp[i][sum + 1000] =
                   findTarget(nums, i + 1, sum - nums[i], target) +
                   findTarget(nums, i + 1, sum + nums[i], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return findTarget(nums, 0, 0, target);
    }
};
