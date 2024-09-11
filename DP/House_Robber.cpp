// problem:  https://leetcode.com/problems/house-robber/description/
/*
Approach:1 {Recursion)
Time Complexity: 𝑂(2^𝑛)
Space Complexity: 𝑂(𝑛)
It will give TLE
*/
class Solution {
public:
    int houseRob(vector<int>& nums,int i){
    if(i<0)
     return 0;
    return max(nums[i]+houseRob(nums,i-2),houseRob(nums,i-1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
      return houseRob(nums,n-1);
    }
};
/*
Approach:2 {Recursion + Memoization)
Time Complexity: 𝑂(𝑛)
Space Complexity: 𝑂(𝑛)
*/
class Solution {
public:
    int dp[101];
    int houseRob(vector<int>& nums,int i){
     if(i<0)
     return 0;
     if(dp[i]!=-1)
     return dp[i];
    return dp[i]=max(nums[i]+houseRob(nums,i-2),houseRob(nums,i-1));
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
      return houseRob(nums,n-1);
    }
};
/*
Approach:3 (Bottom Up)
Time Complexity: 𝑂(𝑛)
Space Complexity: 𝑂(𝑛)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();

      vector<int> dp(n+1,0);
      //dp[i] = max stolen money till i house
      dp[1]=nums[0];
      for(int i=2;i<=n;i++){
        dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
      }
     return dp[n];
    }
};
