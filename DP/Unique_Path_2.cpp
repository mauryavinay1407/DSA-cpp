// problem: https://leetcode.com/problems/unique-paths-ii/description/

/*
Approach:1 (Recursion)
Time Complexity:  𝑂(2^(𝑚+𝑛))
Space Complexity: 𝑂(𝑚+𝑛)
It will give TLE
*/
class Solution {
public:
    int finduniquePathsWithObstacles(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i==m-1 && j==n-1 && grid[i][j]==0)
        return 1;
        if(i>=m || j>=n || grid[i][j]==1)
        return 0;
        return finduniquePathsWithObstacles(grid,i,j+1,m,n)+finduniquePathsWithObstacles(grid,i+1,j,m,n);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return finduniquePathsWithObstacles(grid,0,0,m,n);
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
    int finduniquePathsWithObstacles(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i==m-1 && j==n-1 && grid[i][j]==0)
        return 1;
        if(i>=m || j>=n || grid[i][j]==1)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        return dp[i][j]=finduniquePathsWithObstacles(grid,i,j+1,m,n)+finduniquePathsWithObstacles(grid,i+1,j,m,n);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return finduniquePathsWithObstacles(grid,0,0,m,n);
    }
};

/*
Approach:3 (Bottom Up)
Time Complexity: 𝑂(𝑚×𝑛)
Space Complexity: 𝑂(𝑚×𝑛)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0])
        return 0;
        if(m==1 && n==1)
        return 1;
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            if(grid[i][0])
            break;
            else
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            if(grid[0][j])
            break;
            else
            dp[0][j]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j])
                dp[i][j]=0;
                else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
