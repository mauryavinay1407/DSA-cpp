// problem  :  https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1

/*
Approach - using Prims Algorithm
Time Complexity     : O(N^2 * logN)
Space Complexity    : O(N)
*/

class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        int totalCost = 0;
        int edgesUsed = 0;
    
        // Min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
    
        while (!pq.empty() && edgesUsed < n) {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
    
            if (visited[u]) continue;
    
            visited[u] = true;
            totalCost += cost;
            edgesUsed++;
    
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int manhattan = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    pq.push({manhattan, v});
                }
            }
        }
    
        return totalCost;
    }
};
