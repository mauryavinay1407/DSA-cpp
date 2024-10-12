// problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

/*
Approach: Bottom Up
Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 == dp[i])
                        count[i] += count[j];
                    else if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }
        int LIS = *max_element(dp.begin(), dp.end());
        int result = 0;
        for(int i=0;i<dp.size();i++){
            if(LIS==dp[i])
                result+=count[i];
        }
        return result;
    }
};
