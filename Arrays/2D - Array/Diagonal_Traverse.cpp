// problem : https://leetcode.com/problems/diagonal-traverse

/*
Approach - By using coordinate bucketing
Time Complexity        :  O(M*N)
Space Complexity       :  O(1)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result(m * n);
        int row = 0, col = 0;

        for (int i = 0; i < m * n; i++) {
            result[i] = mat[row][col];
            if ((row + col) % 2 == 0) {
                if (col == n - 1)
                    row++;
                else if (row == 0)
                    col++;
                else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1)
                    col++;
                else if (col == 0)
                    row++;
                else {
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};
