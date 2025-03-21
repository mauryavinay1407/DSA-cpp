//  leetcode     :   https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

//  gfg          :   https://www.geeksforgeeks.org/problems/maximum-profit4657/1

/*
Approach - Using Recursion and Memoization
Time Complexity    :  O(N*k)
Space Complexity   :  O(N*k)
*/

class Solution {
  public:
    int findMaxProfit(vector<int>& prices,int i,int k,int c,bool canBuy,vector<vector<vector<int>>>& dp){
        if(i == prices.size() || c == k){
            return 0;
        }
        
        if(dp[i][c][canBuy] != -1){
            return dp[i][c][canBuy];
        }
        
        if(canBuy){
            int taken = findMaxProfit(prices,i+1,k,c,false,dp) - prices[i];
            int skip = findMaxProfit(prices,i+1,k,c,true,dp);
            return dp[i][c][canBuy] = max(taken,skip);
        }
        else{
            int taken = prices[i] + findMaxProfit(prices,i+1,k,c+1,true,dp);
            int skip = findMaxProfit(prices,i+1,k,c,false,dp);
            return dp[i][c][canBuy] = max(taken,skip);
        }
    }
    
    int maxProfit(int k,vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (k+1,vector<int>(2,-1)));
        return findMaxProfit(prices,0,k,0,true,dp);
    }
};
