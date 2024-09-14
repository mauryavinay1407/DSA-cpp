// problem:  https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Topics: dp,dfs,topological sort

/*
Approach:1 (DFS)
Time Complexity: O(4 ^ (rows * cols)) //  all elements = rows*cols will go in 4 direction
Space Complexity:O(rows * cols) // due to recusrion stack
Time Limit Exceed.
*/
class Solution {
public:
    int rows,cols;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& matrix,int i,int j,int parent){
        if(i<0||j<0||i>=rows||j>=cols||matrix[i][j]<=parent)
          return 0;
       int maxPath = 0;

    for (int k = 0; k < 4; k++) {
        int new_i = i + directions[k][0];
        int new_j = j + directions[k][1];

        if (new_i >= 0 && new_j >= 0 && new_i < rows && new_j < cols && matrix[new_i][new_j] > matrix[i][j]) {
         maxPath = max(maxPath, dfs(matrix, new_i, new_j, matrix[i][j]));
        }
    }
    return 1 + maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     rows=matrix.size();
     cols=matrix[0].size();
     int maxPath=INT_MIN;
     for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           maxPath=max(maxPath,dfs(matrix,i,j,-1));
        }
     }
     return maxPath;
    }
};

/*
Approach:2 (DFS + Memoization)
Time Complexity: O(rows * cols)
Space Complexity: O(rows * cols)
*/
class Solution {
public:
    int dp[200][200];
    int rows,cols;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& matrix,int i,int j,int parent){
        if(i<0||j<0||i>=rows||j>=cols||matrix[i][j]<=parent)
          return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
       int maxPath = 0;

    for (int k = 0; k < 4; k++) {
        int new_i = i + directions[k][0];
        int new_j = j + directions[k][1];

        if (new_i >= 0 && new_j >= 0 && new_i < rows && new_j < cols && matrix[new_i][new_j] > matrix[i][j]) {
           dp[i][j]=maxPath = max(maxPath, dfs(matrix, new_i, new_j, matrix[i][j]));
           // or dp[i][j]=maxPath after finding maxPath
        }
    }

    return dp[i][j]=1 + maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     rows=matrix.size();
     cols=matrix[0].size();
     memset(dp,-1,sizeof(dp));
     int maxPath=INT_MIN;
     for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           maxPath=max(maxPath,dfs(matrix,i,j,-1));
        }
     }
     return maxPath;
    }
};


