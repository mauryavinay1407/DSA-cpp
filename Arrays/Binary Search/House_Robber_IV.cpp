// problem : https://leetcode.com/problems/house-robber-iv

/*
Approach- Using Binary Search                 Hint:  maximum of minimum or minimum if maximum
Time Complexity    : O(logN)
Space Complexity   : O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums, int mid, int k) {
        int i = 0;
        while (i < nums.size()) {
            if (mid >= nums[i]) {
                k--;
                i += 2;
            } else {
                i++;
            }
            if (k == 0) {
                return true;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid, k)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
