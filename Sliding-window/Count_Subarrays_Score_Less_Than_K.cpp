// problem  :  https://leetcode.com/problems/count-subarrays-with-score-less-than-k

/*
Approach - Using typical sliding window
Time Complexity     : O(N)
Space Complexity    : O(1)
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0, j = 0;
        long long sum = 0;
        long long result = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            result += (j - i + 1);
            j++;
        }
        return result;
    }
};
