// problem: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

/*
Approach-1:  by finding all subsets of an array( Recusrion)
Time Complexity: O(2^N)
Space Complexity: O(1)
*/

class Solution {
public:
    int countMax(vector<int>& nums,int i,int maxxi,int temp){
 if (i == nums.size()) {
        return (temp == maxxi) ? 1 : 0;
    }
    
    int taken = countMax(nums, i + 1, maxxi, temp | nums[i]);
    
    int skip = countMax(nums, i + 1, maxxi, temp);
    
    return taken + skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxxi=0;
        for(auto& num: nums)
        maxxi=maxxi | num ;
        return countMax(nums,0,maxxi,0);
    }
};

/*
Approach-2:  by finding all subsets of an array( Recusrion + Memoization)
Time Complexity: O(N*maxOr)
Space Complexity: O(N*maxOr)
*/

class Solution {
public:
    int countMax(vector<int>& nums, int i, int maxxi, int temp,
                 vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return (temp == maxxi) ? 1 : 0;
        }
        if (dp[i][temp] != -1)
            return dp[i][temp];
        int taken = countMax(nums, i + 1, maxxi, temp | nums[i], dp);

        int skip = countMax(nums, i + 1, maxxi, temp, dp);

        return dp[i][temp] = taken + skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxxi = 0;
        for (auto& num : nums)
            maxxi = maxxi | num;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(maxxi + 1, -1));
        return countMax(nums, 0, maxxi, 0, dp);
    }
};
