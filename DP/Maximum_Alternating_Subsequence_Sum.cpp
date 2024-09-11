// problem: https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/
/*
Approach:1 (Recursion)
Time: O(2^n)
Space: O(n)
It will give TLE
*/
class Solution {
public:
    using ll=long long;
    ll findMaxSum(vector<int>& nums,int i,bool isEven){
        if(i>=nums.size())
        return 0;
     ll skip=findMaxSum(nums,i+1,isEven);
     ll value=nums[i];
     if(!isEven)
     value=-value;
     ll take=value + findMaxSum(nums,i+1,!isEven);
     return max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        return findMaxSum(nums,0,true);
    }
};

/*
Approach:1 (Recursion + Memoization)
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    using ll=long long;
    ll dp[100001][2];
    ll findMaxSum(vector<int>& nums,int i,bool isEven){
        if(i>=nums.size())
        return 0;
     if(dp[i][isEven]!=-1)
     return dp[i][isEven];
     ll skip=findMaxSum(nums,i+1,isEven);
     ll value=nums[i];
     if(!isEven)
     value=-value;
     ll take=value + findMaxSum(nums,i+1,!isEven);
     return dp[i][isEven]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return findMaxSum(nums,0,true);
    }
};

/*
Approach:3 (Bottom-up)
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<long>> dp(n, vector<long>(2, 0));

        dp[0][0] = max(-nums[0], 0);
        dp[0][1] = max(nums[0], 0);
            
        for(int i = 1; i < n; i++) {
            
            dp[i][0] = max(dp[i-1][1] - nums[i], dp[i-1][0]);
            
            dp[i][1] = max(dp[i-1][0] + nums[i], dp[i-1][1]);
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
