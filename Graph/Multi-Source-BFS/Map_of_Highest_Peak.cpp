// problem : https://leetcode.com/problems/map-of-highest-peak

/*
Approach : Using Multi-Source BFS
Time Complexity    :  O(m * n)
Space Complexity   :  O(m * n)
*/
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool check(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> heights(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    heights[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }
        while (!q.empty()) {
            auto [pos, d] = q.front();
            auto [x, y] = pos;
            q.pop();
            for (auto& dir : directions) {
                int i = x + dir[0];
                int j = y + dir[1];
                if (check(i, j, m, n) && heights[i][j] == -1) {
                    heights[i][j] = d + 1;
                    q.push({{i, j}, d + 1});
                }
            }
        }
        return heights;
    }
};
