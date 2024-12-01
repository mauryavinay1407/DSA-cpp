// problem: https://leetcode.com/problems/valid-arrangement-of-pairs

/*
Approach-1:         Using Hierholzer's Algorithm (DFS Using Recursion)
                    steps required: 
                          1. Build the adjacency list
                          2. Build the indegree and outdegree
                          3. Find the startNode and EulerPath
Time Complexity:    O(V+E)
Space Complexity:   O(V)
*/

class Solution {
public:
    void findEulerPath(unordered_map<int, vector<int>>& adj, vector<int>& EulerPath, int u) {
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back(); // Remove the edge after using it
            findEulerPath(adj, EulerPath, v);
        }
        EulerPath.push_back(u); // Add node after traversing all its edges
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        // Build the graph
        for (auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        // Find the start node
        int startNode = pairs[0][0];
        for (auto& it : adj) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        // Perform Hierholzer's Algorithm
        vector<int> EulerPath;
        findEulerPath(adj, EulerPath, startNode);

        // Reverse the path to construct the result
        reverse(EulerPath.begin(), EulerPath.end());
        vector<vector<int>> result;
        for (int i = 0; i < EulerPath.size() - 1; i++) {
            result.push_back({EulerPath[i], EulerPath[i + 1]});
        }

        return result;
    }
};

/*
Approach-2:         Using Hierholzer's Algorithm (DFS Using stack)
                    steps required: 
                          1. Build the adjacency list
                          2. Build the indegree and outdegree
                          3. Find the startNode and EulerPath
Time Complexity:    O(V+E)
Space Complexity:   O(V)
*/

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> indegree, outdegree;
         // Build the graph
        for (auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); 
            outdegree[u]++;
            indegree[v]++;
        }
        // Find the start node
        int startNode = pairs[0][0];
        for (auto& it : adj) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        vector<int> EulerPath; // to store my eulerpath
        stack<int> st;         // to perform dfs
        st.push(startNode);

        while (!st.empty()) {
            int curr = st.top();
            if (!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }
       //Build your result
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;
        for (int i = 0; i < EulerPath.size() - 1; i++) {
            result.push_back({EulerPath[i], EulerPath[i + 1]});
        }
        return result;
   }
};
