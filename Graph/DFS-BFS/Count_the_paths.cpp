// problem : https://www.geeksforgeeks.org/problems/count-the-paths4332/1

/*
Approach  -  Using DFS + DP for memoization
Time Complexity       :   O(V + E)
Space Complexity      :   O(V + E)
*/

class Solution {
public:
    int dfs(unordered_map<int,vector<int>>& adj,int node,int dest,vector<int>& dp){
        if(node == dest){
            return 1;
        }
        
        if(dp[node] != -1){
            return dp[node];
        }
        
        int count = 0;
        
        for(auto& v : adj[node]){
            count += dfs(adj,v,dest,dp);
        }
        
        return dp[node] = count;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        unordered_map<int,vector<int>> adj;
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> dp(V,-1);
        
        return dfs(adj,src,dest,dp);
    }
};
