// problem : https://leetcode.com/problems/longest-nice-subarray

/*
Approach- Using sliding window
Time Complexity:   O(N)
Space Complexity:  O(1)
*/
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int result = 0;
        int temp = 0;
        int i=0,j=0;
        while(j < nums.size()){
            while(temp & nums[j]){
                temp ^= nums[i];
                i++;
            }
            result  = max(result,j - i + 1);
            temp |= nums[j];
            j++;
        }
        return result;
    }
};
