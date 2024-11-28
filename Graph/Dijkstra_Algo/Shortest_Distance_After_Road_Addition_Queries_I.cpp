// problem:  https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i

/*
Approach-1: Using BFS
Time Complexity:    O(V + E)
Space Complexity:    O(V)
*/
class Solution {
public:
    int BFS(unordered_map<int,vector<int>>& adj, int n){
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int distance = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                int temp = q.front();
                q.pop();
                if(temp == n - 1)
                    return distance;
                for(auto& v : adj[temp]){
                    if(!visited[v]){
                        visited[v]=true; 
                        q.push(v);
                    }
                }
            }
            distance++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        vector<int> result;
        for(int i=0; i<n-1;i++)
            adj[i].push_back(i+1);
        for(auto& q : queries){
            adj[q[0]].push_back(q[1]);
            int d = BFS(adj,n);
            result.push_back(d);
        }
        return result;
    }
};

/*
Approach-2: Using Dijsktra Algorithm
Time Complexity:    O(Q⋅((n+Q)⋅log(n)))   where Q = no. of queries
Space Complexity:   O(n+Q)
*/
class Solution {
public:
    using P = pair<int, int>;
    int Dijkstra(unordered_map<int, vector<int>>& adj, int n) {
        vector<int> result(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        result[0] = 0;
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            for (auto& adjNode : adj[node]) {
                int wt = 1;
                if (dist + wt < result[adjNode]) {
                    result[adjNode] = dist + wt;
                    pq.push({dist + wt, adjNode});
                }
            }
        }
        return result[n - 1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> result;
        for (int i = 0; i < n - 1; i++)
            adj[i].push_back(i + 1);
        for (auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            int d = Dijkstra(adj, n);
            result.push_back(d);
        }
        return result;
    }
};
