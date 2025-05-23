// problem  :  https://www.geeksforgeeks.org/problems/dice-throw5349/1

/*
Approach - Using recursion + memoization
Time Complexity       :  O(N^2)
Space Complexity      :  O(N^2)
*/

class Solution {
public:
    int findWays(int m,int n,int x,vector<vector<int>>& dp){
        if(x > 0 && x <= m && n == 1){
            return 1;
        }
        if(n == 1 || x < 0){
            return 0;
        }
        if(dp[n][x] != -1){
            return dp[n][x];
        }
        int total = 0;
        for(int i=1;i<=m;i++){
            total += findWays(m,n-1,x-i,dp);
        }
        return dp[n][x] = total;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
        return findWays(m,n,x,dp);
    }
};
