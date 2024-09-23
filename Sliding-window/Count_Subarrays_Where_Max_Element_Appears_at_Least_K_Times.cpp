// problem:  https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

/*
Approach-1:  Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0,j=0;
        for(int i=0;i<nums.size();i++){
            long long temp=0;
            for(int j=i;j<nums.size();j++){
             if(nums[j]==maxi)
             temp++;
             if(temp>=k)
             count++;
            }
        }
        return count;
    }
};

/*
Approach-2:  using sliding window
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count=0;
        int maxi=*max_element(nums.begin(),nums.end());
        long long temp=0;
        int i=0,j=0;
       
        while(j<nums.size()){
         if(nums[j]==maxi)
         temp++;
         while(temp>=k){
           count+=(nums.size()-j);
          if(nums[i]==maxi)
          temp--;
          i++; 
         }
         j++; 
        }       
        return count;
    }
};
