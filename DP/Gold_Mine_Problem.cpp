// problem : https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

/*
Approach - Using DFS + Memoization
Time Complexity     : O(m*n)
Space Complexity    : O(m*n)
*/
class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{-1,1},{0,1},{1,1}};
    int dfs(vector<vector<int>>& mat, int i, int j,vector<vector<int>>& dp){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxGold = 0;
        
        for(auto& dir : directions){
            int new_i = dir[0] + i;
            int new_j = dir[1] + j;
            
            maxGold = max(maxGold,dfs(mat,new_i,new_j,dp));
        }
        return dp[i][j] = maxGold + mat[i][j];
    }
    
    int maxGold(vector<vector<int>>& mat) {
        // code here
        m = mat.size();
        n = mat[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        int result = 0;
        for(int i = 0; i < m; i++){
            result = max(result, dfs(mat,i,0,dp));
        }
        return result;
    }
};
