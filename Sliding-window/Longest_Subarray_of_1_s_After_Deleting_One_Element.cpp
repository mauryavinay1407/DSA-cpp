// problem :  https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

/*
Approach - Using Sliding window
Time Complexity      :   O(N)
Space Complexity     :   O(1)
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int result = 0;
        int count = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                count++;
            }
            if (count > 1) {
                result = max(result, j - i - 1);
                while (nums[i])
                    i++;
                i++;
                count = 1;
            }
            j++;
        }
        result = max(result, j - i - 1);
        return result;
    }
};
