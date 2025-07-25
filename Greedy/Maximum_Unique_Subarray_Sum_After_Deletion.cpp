// problem : https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion

/*
Approach - Using greedy + set
Time Complexity       :   O(N)
Space Complexity      :   O(N)
*/
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0;
        int maxSum = INT_MIN;

        for (auto& num : nums) {
            if (num <= 0) {
                maxSum = max(maxSum, num);
            } else if (!st.count(num)) {
                sum += num;
                st.insert(num);
            }
        }
        return sum == 0 ? maxSum : sum;
    }
};
