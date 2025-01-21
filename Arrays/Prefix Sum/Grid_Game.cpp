// problem : https://leetcode.com/problems/grid-game

/*
Approach-1: Brute force using recursion
Time Complexity   :  O(4^N) 
Space Complexity  :  O(N)
*/
class Solution {
public:
    int n;
    long long robot1(vector<vector<int>>& grid, int i, int j) {
        if (i >= 2 || j >= n) return 1e18; 
        if (i == 1 && j == n-1) {
            long long temp = grid[i][j];
            grid[i][j] = 0;
            return robot2(grid, 0, 0);
        }
        
        long long curr = grid[i][j];
        grid[i][j] = 0;
        
        long long right = robot1(grid, i, j+1);
        long long down = robot1(grid, i+1, j);
        
        grid[i][j] = curr; 
        return min(right, down); 
    }
    
    long long robot2(vector<vector<int>>& grid, int i, int j) {
        if (i >= 2 || j >= n) return 0;
        if (i == 1 && j == n-1) return grid[i][j];
        
        return grid[i][j] + max(robot2(grid, i, j+1), 
                               robot2(grid, i+1, j));
    }
    
    long long gridGame(vector<vector<int>>& grid) {
        n = grid[0].size();
        return robot1(grid, 0, 0);
    }
};
/*
Approach-2: Optimal using prefix sum
Time Complexity   :  O(N) 
Space Complexity  :  O(1)
*/
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottom = 0;
        long long result = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            top -= grid[0][i];
            long long points = max(top, bottom);
            result = min(result, points);
            bottom += grid[1][i];
        }
        return result;
    }
};
