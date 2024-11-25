// problem: https://leetcode.com/problems/sliding-puzzle

/*
Approach: Using Breadth First Search (BFS)
Time Complexity:    O(!6)
Space Complexity:   O(!6)
*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the board to a flattened string representation
        string start = "";
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                start += to_string(board[i][j]);

        string target = "123450";

        // BFS setup
        queue<string> que;
        que.push(start);

        // Adjacency list for possible moves
        vector<vector<int>> moves = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};

        unordered_set<string> visited;
        visited.insert(start);

        int level = 0; // Number of moves

        // BFS traversal
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                string curr = que.front();
                que.pop();

                if (curr == target)
                    return level;

                int zeroIdx = curr.find('0'); // Find the index of '0'
                for (int swapIdx : moves[zeroIdx]) {
                    string newState = curr;
                    swap(newState[zeroIdx],
                         newState[swapIdx]); // Swap '0' with adjacent
                    if (!visited.count(newState)) {
                        que.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            level++; // Increment move count
        }
        return -1; // If target is unreachable
    }
};
