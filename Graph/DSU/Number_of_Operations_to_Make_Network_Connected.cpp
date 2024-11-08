// problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected

/*
Approach-1: Using DFS
Time Complexity:   O(V+E)
Space Complexity:  O(V+E)
*/
class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;
        for (auto v : adj[u]) {
            if (!visited[v])
                DFS(adj, v, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);
        vector<bool> visited(n, 0);
        int components = 0;
        for (auto& node : connections) {
            int u = node[0];
            int v = node[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited);
                components++;
            }
        }
        return components - 1;
    }
};

/*
Approach-2: Using DSU
Time Complexity:   O(N)
Space Complexity:  O(N)
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;
        for (auto& node : connections) {
            if (find(node[0]) != find(node[1])) {
                Union(node[0], node[1]);
                components--;
            }
        }
        return components - 1;
    }
};
