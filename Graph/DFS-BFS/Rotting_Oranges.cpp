// problem: https://leetcode.com/problems/rotting-oranges/description/

/*
Time Complexity:  O(m×n)
Space Complexity: O(m×n)
*/

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int freshOranges = 0; 

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                } else if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }

        if (freshOranges==0)
            return 0;

        int ans = 0; 
        while (!q.empty()) {
            auto [pos, time] = q.front();
            auto [x, y] = pos;
            q.pop();
            for (auto& dir : directions) {
                int new_i = x + dir[0];
                int new_j = y + dir[1];
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                    grid[new_i][new_j] == 1) {
                    grid[new_i][new_j] = 2; 
                    freshOranges--;       
                    q.push({{new_i, new_j},
                            time + 1}); 
                    ans =
                        time + 1;
                }
            }
        }

        return freshOranges == 0 ? ans : -1;
    }
};
