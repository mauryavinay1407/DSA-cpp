// problem: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii

/*
Approach: Using Set
Time Complexity:    O(Q*N*log(N))
Space Complexity:    O(N)
*/

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        vector<int> result;
        for (int i = 0; i < n; i++)
            st.insert(i);
            
        for (auto& q : queries) {
            int src = q[0];
            int dest = q[1];
            if (!st.count(src) || !st.count(dest)) {
                result.push_back(st.size() - 1);
                continue;
            }
            auto it = st.find(src);
            auto temp = next(it);
            while (*temp < dest) {
                st.erase(temp);
                temp = next(it);
            }
            result.push_back(st.size() - 1);
        }
        return result;
    }
};
