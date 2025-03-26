// problem  :  https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid

/*
Approach - Using Sorting and median
Time Complexity    :   O(m*nlog(m*n))
Space Complexity   :   O(m*n)
*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto& row : grid) {
            nums.insert(nums.end(), row.begin(), row.end());
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int mid = i + (j - i) / 2;

        int result = 0;
        int t = nums[mid];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % x == t % x) {
                result += (abs(t - nums[i])) / x;
            } else {
                return -1;
            }
        }
        return result;
    }
};
