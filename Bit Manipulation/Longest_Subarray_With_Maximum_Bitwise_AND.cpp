// problem : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

/*
Approach - by counting accurence range of maximum element
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int result = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(maxi == nums[i]){
                result = max(result, ++count);
            }else{
                count = 0;
            }
        }
        return result;
    }
};
