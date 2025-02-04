// problem :   https://leetcode.com/problems/maximum-ascending-subarray-sum

/*
Approach -  By simply adding the increasing numbers
Time Complexity  :  O(N)
Space Complexity :  O(1)
*/
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int result = sum;
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i] < nums[i + 1]) {
                sum += nums[i + 1];
                result = max(result, sum);
            } else
                sum = nums[i + 1];
            i++;
        }
        return result;
    }
};
