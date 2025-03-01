// problem  : https://leetcode.com/problems/move-zeroes

/*
Approach-1: Brute Force
Time Complexity     :  O(N^2)
Space Complexity    :  O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                int k = i;
                while (k < j) {
                    nums[k] = nums[k + 1];
                    k++;
                }
                nums[j--] = 0;
            }
        }
    }
};
/*
Approach-2: Optimal Using Two Pointer(m-1)
Time Complexity     :  O(N)
Space Complexity    :  O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
/*
Approach-2: Optimal Using Two Pointer(m-2)
Time Complexity     :  O(N)
Space Complexity    :  O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
