// gfg      :      https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
// leetcode :      https://leetcode.com/problems/partition-equal-subset-sum

/*
Approach - Using recursioon  + Memoization
Time Complexity   :    O(N*sum)
Space Complexity  :    O(N*sum)
*/

class Solution {
public:
    bool check(vector<int>& nums, int target, int i, int rem,
               vector<vector<int>>& dp) {
        if (i >= nums.size()) {
            return rem == target;
        }
        if (rem == target) {
            return true;
        }
        if (rem > target) {
            return false;
        }
        if (dp[i][rem] != -1) {
            return dp[i][rem];
        }
        return dp[i][rem] = check(nums, target, i + 1, rem + nums[i], dp) ||
                            check(nums, target, i + 1, rem, dp);
    }
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return check(nums, target, 0, 0, dp);
    }
};
