// problem: https://leetcode.com/problems/longest-increasing-subsequence/description/

/*
Approach-1: Resursion + Memoization
Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidth = 0;
        int n = nums.size();
        vector<int> maxToRight(n, 0);
        maxToRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxToRight[i] = max(maxToRight[i + 1], nums[i]);
        }
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (j < n && nums[i] <= maxToRight[j]) {
                maxWidth = max(maxWidth, j - i);
                j++;
            }
            i++;
        }
        return maxWidth;
    }
};

/*
Approach-2: Bottom up
Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    result = max(result,dp[i]);
                }
            }
        }
        return result;
    }
};
