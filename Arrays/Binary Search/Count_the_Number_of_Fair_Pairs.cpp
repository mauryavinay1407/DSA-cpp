// problem : https://leetcode.com/problems/count-the-number-of-fair-pairs

/*
Approach - Using Binary Search
Time Complexity      :  O(N*logN)
Space Complexity     :  O(N)
*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums),end(nums));
        long long count = 0;
        for(int i = 0 ; i<nums.size();i++){
            int x = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin() - i - 1;
            int y = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin() - i - 1;
            count += (y - x);
        }
        return count;
    }
};
