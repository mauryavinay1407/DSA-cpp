// problem : https://leetcode.com/problems/intersection-of-two-linked-lists

/*
Approach-1 : Brute Force
Time Complexity   :   O((m*n) * (m+n))   
Space Complexity  :   O(1)
*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int resultServers = 0;

        // Traverse through the grid
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    bool canCommunicate = false;

                    // Check for communication in the same row
                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If a server was found in the same row, increment resultServers
                    if (canCommunicate) {
                        resultServers++;
                    } else {
                        // Check for communication in the same column
                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        // If a server was found in the same column, increment resultServers
                        if (canCommunicate) {
                            resultServers++;
                        }
                    }
                }
            }
        }

        return resultServers;
    }
};
/*
Approach-2 : Optimal 
Time Complexity   :   O(m*n)   
Space Complexity  :   O(m+n)
*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        // storing the rows and columns in which servers found
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
      // If a server was found in the same column or row, increase the result
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && ((rowCount[i] > 1) || (colCount[j] > 1)))
                    result++;
            }
        }
        return result;
    }
};
