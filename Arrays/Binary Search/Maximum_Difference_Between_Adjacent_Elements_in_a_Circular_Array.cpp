// problem  :  https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array

/*
Approach - By simple simulation
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int result = 0;
        do {
            result = max(result, abs(nums[i % n] - nums[(i - 1) % n]));
            i++;
        } while (i <= n);

        return result;
    }
};
