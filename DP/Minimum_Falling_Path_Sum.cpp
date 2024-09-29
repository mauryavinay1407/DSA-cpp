// problem:  https://leetcode.com/problems/minimum-falling-path-sum/description

/*
Approach-1: Recursion + Memoization(TLE)
Time Complexity:O(m*n)
Space Complexity: O(101) ~ O(1) (Excluding stack recursion space)
*/

class Solution {
public:
    int dp[101][101];
    int findMinPath(vector<vector<int>>& matrix, int i, int j) {
        if (i == matrix.size() - 1)
            return matrix[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int minSum=INT_MAX;

        for(int shift=-1;shift<=1;shift++){
         if(j+shift>=0 && j+shift<matrix.size())
          minSum=min(minSum,matrix[i][j]+findMinPath(matrix,i+1,j+shift));
        }

        return dp[i][j] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minPathSum = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for (int col = 0; col < matrix[0].size(); col++) {
            minPathSum = min(minPathSum, findMinPath(matrix, 0, col));
        }
        return minPathSum;
    }
};

/*
Approach-2: Bottom up
Time Complexity:O(m*n)
Space Complexity: O(m*n)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> dp(m, vector<int>(m));
        
        for(int col = 0; col<m; col++) {
            dp[0][col] = matrix[0][col];
        }
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < m; col++) {
                dp[row][col] = matrix[row][col] + min({dp[row-1][col], 
                                                 dp[row-1][max(0, col-1)], 
                                                 dp[row-1][min(m-1, col+1)]});
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};
