// problem:  

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
        int m, n;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            m = maze.size();
            n = maze[0].size();

            queue<pair<pair<int, int>, int>> q;
            q.push({{entrance[0], entrance[1]}, 0});

            // make the entrance '+'
            maze[entrance[0]][entrance[1]] = '+';

            while (!q.empty()) {
                int i = q.front().first.first;
                int j = q.front().first.second;
                int steps = q.front().second;
                q.pop();

                for (auto& dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                        maze[new_i][new_j] == '.') {

                        if (new_i == 0 || new_i == m - 1 || new_j == 0 ||
                            new_j == n - 1) {
                            return steps + 1;
                        }

                        maze[new_i][new_j] = '+';
                        q.push({{new_i, new_j}, steps + 1});
                    }
                }
            }

            // no ways 
            return -1;
        }
};

