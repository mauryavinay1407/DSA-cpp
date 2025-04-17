// problem : https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1

/*
Approach- Using Dijkstra Algorithm
Time Complexity    :    O(E^2*logV)
Space Complexity   :    O(V + E)
*/
class Solution {
  public:
    int dijkstra(int src, int dest, int V, vector<vector<int>>adj[]){
        vector<int>dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src});
        dist[src]=0;
        while(!pq.empty()){
            auto &it=pq.top();
            int node=it.second;
            int d=it.first;
            pq.pop();
            
            for(auto& it:adj[node]){
                int adjN=it[0];
                int adjW=it[1];
                if((node==src && adjN==dest) || (node==dest && adjN==src)) continue;
                if(d+adjW<dist[adjN]){
                    dist[adjN]=d+adjW;
                    pq.push({dist[adjN], adjN});
                }
            }
        }
        
        return dist[dest];
    }
  
    int findMinCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int mini=1e9;
        
        for(int i=0; i<edges.size(); i++){
            int dist=(dijkstra(edges[i][0], edges[i][1], V, adj));
            if(dist!=1e9){
                mini=min(mini, dist+edges[i][2]);
            }
        }
        
        return mini;
    }
};
