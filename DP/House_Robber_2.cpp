// problem: https://leetcode.com/problems/house-robber-ii/description/

/*
Approach:1 (Recursion)
Time Complexity: 𝑂(2^𝑛)
Space Complexity: 𝑂(𝑛)
It will give TLE
*/
class Solution {
public:
    int houseRob2(vector<int>& nums,int i,int n){
        if(i>n)
        return 0;
        return max(nums[i]+houseRob2(nums,i+2,n),houseRob2(nums,i+1,n));
    }
    int rob(vector<int>& nums) {
     int n=nums.size();
     if(n==1)
     return nums[0];
     if(n==2)
     return max(nums[0],nums[1]);
     return max(houseRob2(nums,0,n-2),houseRob2(nums,1,n-1));
    }
};
/*
Approach:2 (Recursion + Memoization)
Time Complexity: 𝑂(𝑛)
Space Complexity: 𝑂(𝑛)
*/
class Solution {
public:
    int dp[101];
    int houseRob2(vector<int>& nums,int i,int n){
        if(i>n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        return dp[i]=max(nums[i]+houseRob2(nums,i+2,n),houseRob2(nums,i+1,n));
    }
    int rob(vector<int>& nums) {
     int n=nums.size();
     memset(dp,-1,sizeof(dp));

     if(n==1)
     return nums[0];
     if(n==2)
     return max(nums[0],nums[1]);

     int taking_0th_house=houseRob2(nums,0,n-2);
     memset(dp,-1,sizeof(dp));
     int skipping_0th_house=houseRob2(nums,1,n-1);
       
     return max(taking_0th_house,skipping_0th_house);
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
     vector<int> dp1(n+1,0);
     vector<int> dp2(n+1,0);
     if(n==1)
     return nums[0];
     if(n==2)
     return max(nums[0],nums[1]);
     dp1[1]=nums[0];
     dp2[1]=nums[1];
     
     for(int i=2;i<=n-1;i++)
     dp1[i]=max(dp1[i-2]+nums[i-1],dp1[i-1]);

     for(int i=2;i<=n-1;i++)
     dp2[i]=max(dp2[i-2]+nums[i],dp2[i-1]);
       
     return max(dp1[n-1],dp2[n-1]);
    }
};
