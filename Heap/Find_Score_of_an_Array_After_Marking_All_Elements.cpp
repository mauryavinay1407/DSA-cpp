// problem : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements

/*
Approach: using mean - heap
Time Complexity   :    O(N*logN)
Space  Complexity :    O(N)
*/
class Solution {
public:
    using P = pair<int, int>;
    long long findScore(vector<int>& nums) {
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});
        long long score = 0;
        vector<bool> visited(nums.size(), 0);
        while (!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            if (!visited[idx]) {
                score += nums[idx];
                visited[idx] = true;
            } else
                continue;
            if (idx != 0)
                visited[idx - 1] = true;
            visited[idx + 1] = true;
        }
        return score;
    }
};
