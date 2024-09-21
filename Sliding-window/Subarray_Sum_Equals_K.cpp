// problem:  https://leetcode.com/problems/subarray-sum-equals-k/description/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.count(sum-k))
             count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
