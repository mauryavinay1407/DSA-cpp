// leetcode :  https://leetcode.com/problems/spiral-matrix
// gfg      :  https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

/*
Approach- Using simple loop
Time Complexity  :  O(M*N)
Space Complexity :  O(1)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        int idx = 0;
        while (top <= down && left <= right) {
            // idx = 0   -> left  to right
            if (idx == 0) {
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            // idx = 1   -> top   to down
            if (idx == 1) {
                for (int i = top; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            // idx = 2   -> right to left
            if (idx == 2) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            // idx = 3   -> down  to top
            if (idx == 3) {
                for (int i = down; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            idx = (idx + 1) % 4;
        }
        return result;
    }
};
