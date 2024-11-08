// problem :  https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph

/*
Approach-1: Using DFS
Time Complexity:    O(n+E)
Space Complexity:   O(n+E)
*/

class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited,
             int& size) {
        visited[u] = true;
        size++;
        for (auto& v : adj[u]) {
            if (!visited[v])
                DFS(adj, v, visited, size);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long remainingSize = n;
        long long result = 0;
        int size = 0;
        vector<bool> visited(n, 0);
        vector<vector<int>> adj(n);
        for (auto& node : edges) {
            int u = node[0];
            int v = node[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = 0;
                DFS(adj, i, visited, size);
                result += size * (remainingSize - size);
                remainingSize -= size;
            }
        }
        return result;
    }
};

/*
Approach-2: Using DSU
Time Complexity:    O(n+E)
Space Complexity:   O(n)
*/

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if (rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (auto& node : edges)
            Union(node[0], node[1]);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int parent = find(i);
            mp[parent]++;
        }
        long long remainingSize = n;
        long long result = 0;
        for (auto& m : mp) {
            long long size = m.second;
            result += size * (remainingSize - size);
            remainingSize -= size;
        }
        return result;
    }
};
