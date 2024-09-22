// problem:  https://leetcode.com/problems/subarray-product-less-than-k/description/

/*
Approach-1:  Brute Force 
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
   int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int prod = 1;
        for (int j = i; j < nums.size(); j++) {
            prod *= nums[j];
            if (prod < k) {
                count++;
            } else {
                break;
            }
        }
    }

    return count;
}
};

/*
Approach-2:  Optimal solution
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int prod=1;
        int count=0;
        while(j<nums.size()){
          prod*=nums[j];
          while(i<=j && prod>=k){
            prod/=nums[i];
            i++;
          }
         count+=(j-i+1);
         
          j++;
        }
         return count;
    }
};
