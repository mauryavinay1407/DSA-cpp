// problem: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner

/*
Approach-1: Using BFS 0-1
Time Complexity:     O(m*n)
Space Complexity:    O(m*n)
*/
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        result[0][0] = 0;
        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();
            for (auto& [dx, dy] : directions) {
                int new_i = i + dx;
                int new_j = j + dy;
                if (isValid(new_i, new_j)) {
                    int cost = result[i][j] + grid[new_i][new_j];
                    if (cost < result[new_i][new_j]) {
                        result[new_i][new_j] = cost;

                        if (grid[new_i][new_j])
                            dq.push_back({new_i, new_j});
                        else
                            dq.push_front({new_i, new_j});
                    }
                }
            }
        }
        return result[m - 1][n - 1];
    }
};

/*
Approach-2: Using Dijkstra's Algorithm
Time Complexity:     O(m*n log(m*n))
Space Complexity:    O(m*n)
*/
class Solution {
public:
    using P = pair<int, pair<int, int>>;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [dist, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();
            for (auto& [dx, dy] : directions) {
                int new_i = i + dx;
                int new_j = j + dy;
                if (isValid(new_i, new_j)) {
                    int wt = (grid[i][j] == 1);
                    if (dist + wt < result[new_i][new_j]) {
                        result[new_i][new_j] = dist + wt;
                        pq.push({dist + wt, {new_i, new_j}});
                    }
                }
            }
        }
        return result[m - 1][n - 1];
    }
};
