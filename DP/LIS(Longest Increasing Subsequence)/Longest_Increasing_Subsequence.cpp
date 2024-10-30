// problem: https://leetcode.com/problems/longest-increasing-subsequence/description/

/*
Approach-1: Resursion + Memoization
Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

class Solution {
public:
    int dp[2501][2501];
    int findLengthOfLIS(vector<int>& nums, int i, int mini) {
        if (i == nums.size())
            return 0;
        if (mini != -1 && dp[i][mini] != -1)
            return dp[i][mini];
        int take = 0;
        if (mini == -1 || nums[mini] < nums[i])
            take = 1 + findLengthOfLIS(nums, i + 1, i);

        int skip = findLengthOfLIS(nums, i + 1, mini);
        if (mini != -1)
            dp[i][mini] = max(take, skip);
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return findLengthOfLIS(nums, 0, -1);
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

/*
Approach-3: Using Binary Search (Patience sorting)    (i.e internally use b_search bcuz lower/bound takes logn time to search)
Time Complexity:       O(N*logN)
Space Complexity:      O(N)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sortedArr;
        for(auto& num : nums){
            auto lb = lower_bound(sortedArr.begin(),sortedArr.end(),num);
            if(lb==sortedArr.end())
                sortedArr.push_back(num);
            else
                *lb = num;
        }
        return sortedArr.size();
    }
};

/*
Approach-4:  using same but in place (Most optimal)
Time Complexity:       O(N*logN)
Space Complexity:      O(1)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = lower_bound(nums.begin(), nums.begin() + len, nums[i]) -
                    nums.begin();
            if (j == len)
                len++;
            nums[j] = nums[i];
        }
        return len;
    }
};
