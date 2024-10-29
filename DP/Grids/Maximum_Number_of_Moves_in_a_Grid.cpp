// problem:  https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

/*
Approach-1:  Recursion + Memoization            (without memoization, it would take O(m*3^n)
Time Complexity:   O(M*N)
Space Complexity:  O(M*N)
*/
class Solution {
public:
    int m, n;
    int dp[1001][1001];
    bool checkIfValid(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int findMaxMoves(vector<vector<int>>& grid, int i, int j, int value) {
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = 0, middle = 0, down = 0;
        if (checkIfValid(i - 1, j + 1) && value < grid[i - 1][j + 1])
            up = 1 + findMaxMoves(grid, i - 1, j + 1, grid[i - 1][j + 1]);
        if (checkIfValid(i, j + 1) && value < grid[i][j + 1])
            middle = 1 + findMaxMoves(grid, i, j + 1, grid[i][j + 1]);
        if (checkIfValid(i + 1, j + 1) && value < grid[i + 1][j + 1])
            down = 1 + findMaxMoves(grid, i + 1, j + 1, grid[i + 1][j + 1]);

        return dp[i][j] = max({up, middle, down});
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int result = 0;
        for (int i = 0; i < m; i++) {
            result = max(result, findMaxMoves(grid, i, 0, grid[i][0]));
        }
        return result;
    }
};

/*
Approach-2: Bottom up
Time Complexity:   O(M*N)
Space Complexity:  O(M*N)
*/

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                int up = 0, middle = 0, down = 0;
                if (i > 0 && grid[i][j] < grid[i - 1][j + 1])
                    up = 1 + dp[i - 1][j + 1];
                if (i >= 0 && grid[i][j] < grid[i][j + 1])
                    middle = 1 + dp[i][j + 1];
                if (i < m - 1 && grid[i][j] < grid[i + 1][j + 1])
                    down = 1 + dp[i + 1][j + 1];

                dp[i][j] = max({up, middle, down});

                if (j == 0)
                    result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};

/*
Approach-2: DFS + Caching(Memoization)
Time Complexity:   O(M*N)
Space Complexity:  O(M*N)
*/
class Solution {
public:
    int m, n;

    vector<vector<int>> directions{{-1, 1},{0, 1},{1,1,}};
    bool isValid(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n); 
        }
    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];
        int moves = 0;
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (isValid(new_i, new_j) && (grid[i][j] < grid[new_i][new_j]))
                moves = max(moves, 1 + DFS(grid, new_i, new_j, dp));
        }
        return dp[i][j] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int result = 0;
        for (int i = 0; i < m; i++)
            result = max(result, DFS(grid, i, 0, dp));
        return result;
    }
};
