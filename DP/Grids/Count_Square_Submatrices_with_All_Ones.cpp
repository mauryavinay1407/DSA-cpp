// problem:  https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

/*
Approach-1: Brute force(rec + memo)
Time Complexity: O(O(m*n*min(m,n)^2)
Space Complexity: O(m*n)
*/

class Solution {
public:
    int m, n;
    int dp[301][301];
    bool checkSquare(vector<vector<int>>& matrix, int i, int j, int d_i,
                     int d_j) {
        for (int row = i; row <= d_i; row++) {
            for (int col = j; col <= d_j; col++) {
                if (matrix[row][col] != 1)
                    return false;
            }
        }
        return true;
    }

    int findSquare(vector<vector<int>>& matrix, int i, int j, int d_i,
                   int d_j) {
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int size = 1, count = 1;
        while (i + size < m && j + size < n &&
               checkSquare(matrix, i, j, i + size, j + size)) {
            count++;
            size++;
        }
        return dp[i][j] = count;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        m = matrix.size();
        n = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 1) {
                    count += findSquare(matrix, i, j, i, j);
                }
            }
        }
        return count;
    }
};

/*
Approach-2:  Optimal (rec + memo)  (same as lc 221)
Time Complexity:    O(m*n)      (time reduced from O(3^(m*n)) to O(m*n) due to memo, because there are m*n cells and for each cell we have to explore 3 call i.e. 3*3*3.....m*n = 3^m*n)         
Space Complexity:   O(m*n)       
*/
class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {

        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        if (matrix[i][j] == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Right
        int right = solve(i, j + 1, matrix, dp);
        // Diagonal
        int diagonal = solve(i + 1, j + 1, matrix, dp);
        // Below
        int below = solve(i + 1, j, matrix, dp);

        return dp[i][j] = 1 + min({right, diagonal, below});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                count += solve(i, j, matrix, dp);
            }
        }
        return count;
    }
};

/*
Approach-3:  Opimal(Bottom up) (same as lc 221)
Time Complexity:   O(m*n)
Space Complexity:  O(m*n)
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1],
                                            dp[i - 1][j - 1]});
                    }
                    count += dp[i][j];
                }
            }
        }
        return count;
    }
};
