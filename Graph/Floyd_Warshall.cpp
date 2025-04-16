// problem  :  https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

/*
Approach - Using nested loops
Time Complexity     : O(V^3)
Space Complexity    : O(1)
*/

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};
