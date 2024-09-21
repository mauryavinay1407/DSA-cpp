// problem:  https://leetcode.com/problems/contiguous-array/description/

/*
Time Complexity: O(n);
Space Complexity: O(n);
*/

class Solution {
public:
   int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> mp;
    mp[0]=-1;
    int maxLength=0;
    int sum=0;
    for(int i=0;i<nums.size();i++){
      sum+=nums[i]==1 ? 1 : -1;
    
    if(mp.count(sum)){
        maxLength=max(maxLength,i-mp[sum]);
    }
    else
      mp[sum]=i;
    }
   return maxLength;
}
};
