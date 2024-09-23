// problem:   https://leetcode.com/problems/minimum-size-subarray-sum/description/

/*
Approach-1: Brute Force
Time Complexity: O(n^2)
Space Complxity: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int minLen=INT_MAX;
      for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum>=target)
            minLen=min(minLen,j-i+1);
        }
      }
     return minLen==INT_MAX ? 0 : minLen;
    }
};


/*
Approach-2: using sliding window 
Time Complexity: O(n)
Space Complxity: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int minLen=INT_MAX;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];

            while(sum>=target){
             minLen=min(minLen,j-i+1);
             sum-=nums[i];
             i++;
            }
            j++;
        }
     return minLen==INT_MAX ? 0 : minLen;
    }
};
