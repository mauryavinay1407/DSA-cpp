// problem : https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition

/*
Approach - Using simple simulation
Time Complexity    :  O(N)
Space Complexity   :  O(1)
*/
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i - 1] % 2 == 0) {
                int half = nums[i - 1] / 2;
                if (nums[i - 2] + nums[i] == half) {
                    result++;
                }
            }
        }
        return result;
    }
};
