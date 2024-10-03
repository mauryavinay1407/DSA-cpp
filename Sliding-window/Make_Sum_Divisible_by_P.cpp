// problem:  https://leetcode.com/problems/make-sum-divisible-by-p/description/

/*
Approach - Using prefix sum
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long Totalsum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = Totalsum % p;
        if (rem == 0)
            return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int result = nums.size();
        long long prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int curr = prefixSum % p;
            int target = (curr - rem + p) % p;
            if (mp.count(target))
                result = min(result, i - mp[target]);
            mp[curr] = i;
        }
        return result == nums.size() ? -1 : result;
    }
};
