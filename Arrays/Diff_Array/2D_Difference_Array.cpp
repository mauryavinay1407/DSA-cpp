// problem : https://www.geeksforgeeks.org/problems/2-d-difference-array/1

/*
Approach - Using difference array technique
Time Complexity        :  O(M*N) 
Space Complexity       :  O(M*N)
*/
class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));

        // Apply all operations in O(q)
        for (auto& op : opr) {
            int v = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];

            diff[r1][c1] += v;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= v;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= v;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
        }

        // Prefix sum (first row-wise, then column-wise)
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        // Add difference array to original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] += diff[i][j];
            }
        }

        return mat;
    }
};
