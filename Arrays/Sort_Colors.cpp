// problem:  https://leetcode.com/problems/sort-colors/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int l=0;
       int m=0;
       int h=nums.size()-1;
      while(m<=h){
          if(nums[m]==2){
              swap(nums[m],nums[h]);
              h--;
          }
          else if(nums[m]==0){
              swap(nums[m],nums[l]);
              l++;
              m++;
          }
          else
          m++;
      }
    }
};
