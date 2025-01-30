// problem :  https://leetcode.com/problems/redundant-connection

/*
Approach- Using DSU
Time Complexity    : O(N * α(N)), where 𝑁 is the number of edges, and 𝛼(𝑁)α(N) is the inverse Ackermann function, which is nearly constant in practical use.
Space Complexity   : O(N)
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
        int parent_x = find(x);
        int parent_y = find(y);
        if (rank[parent_x] > rank[parent_y])
            parent[parent_y] = parent_x;
        else if (rank[parent_x] < rank[parent_y])
            parent[parent_x] = parent_y;
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        parent.resize(V + 1);
        rank.resize(V + 1, 0);
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            if (find(u) == find(v))
                return {u, v};
            else
                Union(u, v);
        }
        return vector<int>{};
    }
};
