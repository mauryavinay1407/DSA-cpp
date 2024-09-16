// problem:  https://leetcode.com/problems/combination-sum-iii/

/*
Time Complexity: O(9^k)
Space Complexity: O(k * 9^k)
where k=no of elements in each combination
*/

class Solution {
public: 
    vector<vector<int>> ans;
    void findCombinationSum3(int k,int target,int start,vector<int>& nums){
     if(target==0 && nums.size()==k){
        ans.push_back(nums);
        return;
     }
     if(nums.size()>k||target<0)
     return;

     for(int i=start;i<=9;i++){
        nums.push_back(i);
        findCombinationSum3(k,target-i,i+1,nums);
        nums.pop_back();
     }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
      findCombinationSum3(k,n,1,nums);
      return ans;
    }
};
