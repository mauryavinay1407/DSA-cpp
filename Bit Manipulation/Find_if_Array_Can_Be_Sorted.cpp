// https://leetcode.com/problems/find-if-array-can-be-sorted

/*
Approach-1: Using Bubble sort
Time Complexity:    O(N^2)
Space Complexity:   O(1)
*/
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (__builtin_popcount(nums[j]) ==
                        __builtin_popcount(nums[j + 1]))
                        swap(nums[j], nums[j + 1]);
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
/*
Approach-2: Using segment sorting check
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int minInRange = nums[0];
        int maxInRange = nums[0];
        int preMax = INT_MIN;
        int countSetBits = __builtin_popcount(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == countSetBits) {
                maxInRange = max(maxInRange, nums[i]);
                minInRange = min(minInRange, nums[i]);
            } else {
                if (preMax > minInRange)
                    return false;

                preMax = maxInRange;
                maxInRange = nums[i];
                minInRange = nums[i];
                countSetBits = __builtin_popcount(nums[i]);
            }
        }
        return preMax < minInRange;
    }
};
