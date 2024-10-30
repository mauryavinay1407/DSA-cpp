# [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array)

/*
Approach-1: Using Longest Increasing Subsequence from left and right (three pass)
Time Complexity:    O(N^2)
Space Complexity:   O(N)
*/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int minRemoval = n;
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j])
                    LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) // bcuz length of mountain arr>=3
                minRemoval = min(minRemoval, n - (LIS[i] + LDS[i] - 1));
        }
        return minRemoval;
    }
};

/*
Approach-2: Using patience (three pass)
Time Complexity:    O(N*logN)
Space Complexity:   O(N)
*/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int minRemoval = n;
        vector<int> LIS(n);
        vector<int> LDS(n);
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            auto lb = lower_bound(temp.begin(), temp.end(), nums[i]);
            LIS[i] = lb - temp.begin() + 1;
            if (lb == temp.end())
                temp.push_back(nums[i]);
            else
                *lb = nums[i];
        }
        temp.clear();
        for (int i = n - 1; i >= 0; i--) {
            auto lb = lower_bound(temp.begin(), temp.end(), nums[i]);
            LDS[i] = lb - temp.begin() + 1;
            if (lb == temp.end())
                temp.push_back(nums[i]);
            else
                *lb = nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) //  length of mountain arr should be >= 3
                minRemoval = min(minRemoval, n - (LIS[i] + LDS[i] - 1));
        }
        return minRemoval;
    }
};
