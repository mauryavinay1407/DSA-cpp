// problem: https://leetcode.com/problems/unique-paths/description/

/*
Approach:1 (Recursion)
Time Complexity: O(2^(m+n))
Space Complexity: O(m+n)
It will give TLE
*/
class Solution {
public:

    int findUniquePaths(int i,int j,int m,int n){
        if(i==m-1 && j==n-1)
        return 1;
        if(i>=m || j>=n)
        return 0;
        return findUniquePaths(i,j+1,m,n)+findUniquePaths(i+1,j,m,n);
    }
    int uniquePaths(int m, int n) {

     return findUniquePaths(0,0,m,n);
    }
};
/*
Approach:2 (Recursion + Memoization)
Time Complexity: 𝑂(𝑚×𝑛)
Space Complexity: 𝑂(𝑚×𝑛)
*/
class Solution {
public:
    int dp[101][101];
    int findUniquePaths(int i,int j,int m,int n){
        if(i==m-1 && j==n-1)
        return 1;
        if(i>=m || j>=n)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        return dp[i][j]=findUniquePaths(i,j+1,m,n)+findUniquePaths(i+1,j,m,n);
    }
    int uniquePaths(int m, int n) {
     memset(dp,-1,sizeof(dp));
     return findUniquePaths(0,0,m,n);
    }
};

/*
Approach:3 (Bottom Up)
Time Complexity: 𝑂(𝑚×𝑛)
Space Complexity: 𝑂(𝑚×𝑛)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,1));
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
         dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
     return dp[m-1][n-1];
    }
};
