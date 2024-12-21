// problem : https://leetcode.com/problems/maximum-number-of-k-divisible-components

/*
Approach :  Using Topo Sort
Time Complexity   :   O(N)
Space Complexity  :   O(N)
*/
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        if (n == 1)
            return 1;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        vector<long long> nodes(values.begin(),values.end());
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 1)
                q.push(i);
        int result = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            indegree[u]--;
            long long carry = 0;
            if (nodes[u] % k == 0)
                result++;
            else
                carry = nodes[u];
            for (auto& v : adj[u]) {
                if (indegree[v] == 0)
                    continue;
                indegree[v]--;
                nodes[v] += carry;
                if (indegree[v] == 1)
                    q.push(v);
            }
        }
        return result;
    }
};
