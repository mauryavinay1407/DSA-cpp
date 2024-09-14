// problem: https://leetcode.com/problems/number-of-islands/

/*
Approach:1 (DFS)
Time Complexity: O(m*n)
Space Complexity: O(m*n) (due to recursion depth in the DFS).
*/

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<char>>& grid,int i,int j){
    if(i<0||j<0||i>=m||j>=n||grid[i][j]!='1'){
        return;
    }
      grid[i][j]='$';
     for(auto& dir:directions){
      int new_i=i+dir[0];
      int new_j=j+dir[1];
       if(new_i<m && new_j<n && new_i>=0 && new_j>=0)
       dfs(grid,new_i,new_j);
     }
    }
    int numIslands(vector<vector<char>>& grid) {
      m=grid.size();
      n=grid[0].size();
      int countIslands=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
             dfs(grid,i,j);
             countIslands++;
            }
        }
      }
      return countIslands;
    }
};
/*
Approach:2 (BFS)
Time Complexity: O(m * n)
Space Complexity: O(min(m, n))
*/
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '$'; 

        while (!q.empty()) {
            auto [cur_i, cur_j] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int new_i = cur_i + dir[0];
                int new_j = cur_j + dir[1];

                if (new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && grid[new_i][new_j] == '1') {
                    q.push({new_i, new_j});
                    grid[new_i][new_j] = -1; 
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
      m=grid.size();
      n=grid[0].size();
      int countIslands=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
             bfs(grid,i,j);
             countIslands++;
            }
        }
      }
      return countIslands;
    }
};
