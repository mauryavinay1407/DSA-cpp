//  problem  :  https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

/*
Approach -  Using sorting and greedy
Time Complexity      :  O(N*logN)
Space Complexity     :  O(1)
*/
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int minValue = nums[0];
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] - minValue > k){
                count++;
                minValue = nums[i];
            }
        }
        return count;
    }
};
