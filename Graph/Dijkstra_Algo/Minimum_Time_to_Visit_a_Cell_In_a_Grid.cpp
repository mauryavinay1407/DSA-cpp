// problem:  https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid

/* 
Approach: Using Dijkstra Algorithm
Time Complexity:    O(M*N*log(M*N))       time of dijkstra - O(E*log(V)) here no of edges(E) = M*N and no of vertices(v) = M*N
Space Complexity:   O(M*N)
*/

class Solution {
public:
    using P = pair<int, pair<int, int>>;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();
            for (auto& [dx, dy] : directions) {
                int new_i = i + dx;
                int new_j = j + dy;
                if (isValid(new_i, new_j)) {
                    int arrivalTime = time + 1;
                    int requiredTime = grid[new_i][new_j];

                    if (arrivalTime < requiredTime) {
                        int wait = (requiredTime - arrivalTime) % 2 == 0 ? 0 : 1;
                        arrivalTime = requiredTime + wait;
                    }
                    if (arrivalTime < result[new_i][new_j]) {
                        result[new_i][new_j] = arrivalTime;
                        pq.push({arrivalTime, {new_i, new_j}});
                    }
                }
            }
        }
        return result[m - 1][n - 1];
    }
};
