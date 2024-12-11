// problem : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation

/*
Approach:             using sliding window technique
Time Complexity:      O(N*logN)
Space Complexity:     O(N)
*/
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        vector<int> lower(n, 0);
        vector<int> upper(n, 0);
        for (int i = 0; i < n; i++) {
            lower[i] = nums[i] - k;
            upper[i] = nums[i] + k;
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && upper[i] >= lower[j]) {
                count++;
                j++;
            }
            result = max(result, count);
            count--;
        }
        return result;
    }
};
