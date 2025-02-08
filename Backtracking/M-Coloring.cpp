// problem :  https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

/*
Approach-1 :  Using DFS
Time Complexity     :    O(m^v)
Space Complexity    :    O(V + E)   due to adjacent list
*/
class Solution {
  public:
    bool DFS(unordered_map<int,vector<int>>& adj,int u,vector<int>& colors,int m){
      // checking right color
        for(int i=0;i<m;i++){
            bool isPossible = 1;
          // checking the adjacent vertices dont have same color
            for(auto& v : adj[u]){
                if(colors[v] == i){
                    isPossible = 0;
                    break;
                }
            }
            if(!isPossible)
                continue;
            
            colors[u] = i;
            
            isPossible = 1;
          // checking whether can proceed with current color
            for(auto& v : adj[u]){
                if(colors[v] == -1 && !DFS(adj,v,colors,m)){
                    isPossible = 0;
                    break;
                }
            }
            if(isPossible)
                return true;
            
            colors[u] = -1;
        }
        return false;
    }
    bool graphColoring(int V, vector<pair<int, int>>& edges, int m) {
        unordered_map<int,vector<int>> adj;
        vector<int> colors(V,-1);
        for(auto& e : edges){
            int a = e.first;
            int b = e.second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<V;i++){
            if(colors[i] == -1 && !DFS(adj,i,colors,m))
                return false;
        }
        return true;
    }
};
/*
Approach-2 :  Using pure backtracking
Time Complexity     :    O(m^v)
Space Complexity    :    O(V + E)   due to adjacent list
*/
class Solution {
  public:
    bool mColoring(unordered_map<int,vector<int>>& adj, int u, vector<int>& colors, int m) {
        // Base case: If all vertices are assigned a color, return true
        if (u == colors.size()) 
            return true;
        
        // Try assigning each of the 'm' colors to the current vertex
        for (int i = 0; i < m; i++) {
            bool isPossible = true;

            // Check if the current color is valid (i.e., no adjacent vertex has the same color)
            for (auto& v : adj[u]) {
                if (colors[v] == i) {
                    isPossible = false; // Conflict detected, cannot use this color
                    break;
                }
            }
            if (!isPossible)
                continue;

            // Assign color 'i' to vertex 'u'
            colors[u] = i;
            
            // Recur for the next vertex
            if (mColoring(adj, u + 1, colors, m))
                return true; // If successful, return true
            
            // Backtrack: Remove the assigned color and try another
            colors[u] = -1;
        }
        
        // If no color can be assigned, return false
        return false;
    }

    bool graphColoring(int V, vector<pair<int, int>>& edges, int m) {
        unordered_map<int,vector<int>> adj;
        vector<int> colors(V, -1); // Initialize all colors to -1 (unassigned)
        
        // Construct adjacency list
        for (auto& e : edges) {
            int a = e.first;
            int b = e.second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        // Start backtracking from the first vertex
        return mColoring(adj, 0, colors, m);
    }
};
