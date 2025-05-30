//  problem  :  https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

/*
Approach  - Using DFS
Time Complexity       :  O(V+E)
Space Complexity      :  O(N)
*/
class Solution {
public:
    void bfs(vector<int>& edges, vector<int>& dist1, int node1) {
        int n = edges.size();
        vector<bool> visited(n, false);
        queue<int> q;
        visited[node1] = true;
        dist1[node1] = 0;
        q.push(node1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int v = edges[u];
            if (v != -1 && !visited[v]) {
                visited[v] = true;
                dist1[v] = 1 + dist1[u];
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);   // to store the difference from node1 to all
        vector<int> dist2(n, INT_MAX);   // to store the difference from node2 to all

        bfs(edges, dist1, node1);    // to explore dist from node1
        bfs(edges, dist2, node2);    // to explore dist from node2

        int minDist = INT_MAX;
        int result = -1;
        for (int i = 0; i < n; i++) {
            int maxD = max(dist1[i], dist2[i]);

            if (minDist > maxD) {
                minDist = maxD;
                result = i;
            }
        }
        return result;
    }
};
