// problem   :   https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

/*
Approach - Using Bellman Ford
Time Complexity      : O(V * E)
Space Complexity     : O(V)
*/

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> result(V, 1e8);
        result[src] = 0;
        
        for(int c = 1; c<=V-1; c++) {
            
            for(auto &edge : edges) {
                
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
                
            }
            
        }
        
        //Now detect negative cycle
        for(auto &edge : edges) {
            
            int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    return {-1};
                }
        }
        
        return result;
    }
};
