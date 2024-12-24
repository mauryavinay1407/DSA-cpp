// problem : https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees

/*
Approach- Finding the diameter from both trees and divide them (Using BFS)
Time Complexity    :  O(N + M)
Space Complexity   :  O(N + M)
*/

class Solution {
public:
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int source) {
        queue<int> q;
        q.push(source);
        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                farthestNode = curr;
                for (auto& nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            if (!q.empty())
                distance++;
        }
        return {farthestNode, distance};
    }
    int findDiameter(unordered_map<int, vector<int>>& adj) {
        // step-1 find the farthest node from a random node - 0
        auto [farthestNode, dist] = BFS(adj, 0);
        // step-2 : the farthestNode we got above is nothing but one end of the
        // diameter of adj

        // step-3 : Find the farthestnode from the node we got above , that will
        // be the other end of diameter - diameter
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }
    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int merged = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, merged});
    }
};
