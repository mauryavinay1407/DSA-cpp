// problem : https://leetcode.com/problems/maximum-erasure-value

/*
Approach - Using hashmap
Time Complexity        : O(N)
Space Complexity       : O(N)
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int j = 0;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mp[nums[i]]++;
            while (mp[nums[i]] > 1) {
                sum -= nums[j];
                mp[nums[j]]--;
                if (mp[nums[j]] == 0) {
                    mp.erase(nums[j]);
                }
                j++;
            }
            result = max(result, sum);
        }
        return result;
    }
};
