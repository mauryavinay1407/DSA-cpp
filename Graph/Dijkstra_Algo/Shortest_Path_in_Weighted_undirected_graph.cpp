// problem: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

/*
Approach: Using Dijsktra Algorithm
Time Complexity: O(N*logM)
Space Complexity: O(N + M)
*/
class Solution {
  public:
    using P = pair<int,int>;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int,vector<P>> adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<int> result(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        for(int i = 1; i <= n;i++)
            parent[i] = i;
        
        result[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto& v : adj[node]){
                int adjNode = v.first;
                int weight = v.second;
                if(dist + weight < result[adjNode]){
                    result[adjNode] = dist + weight;
                    pq.push({dist + weight, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        vector<int> path;
        int destNode = n;
        if(result[destNode] == INT_MAX)
            return {-1};
        while(destNode != parent[destNode]){
            path.push_back(destNode);
            destNode = parent[destNode];
        }
        path.push_back(1);
        path.push_back(result[n]);
        reverse(path.begin(),path.end());
        
        return path;
    }
};
