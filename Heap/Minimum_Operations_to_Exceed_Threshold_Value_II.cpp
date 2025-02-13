// problem  :  https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii

/*
Approach - Using min heap
Time Complexity     :  O(n*logn)
Space Complexity    :  O(n)
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(),nums.end());
        if(pq.top() >= k)
            return 0;
        while (pq.size() >= 2) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long c = 2LL * a + b;
            pq.push(c);
            result++;
            if (pq.top() >= k)
                return result;
        }
        return result;
    }
};
