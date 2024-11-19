// problem:  https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

/*
Approach : Store element in map and check the size for distinct window size
Time Complexity:      O(N)
Space Complexity:     O(N)    because k can be equals to nums.length
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        long long sum = 0;
        long long result = 0;
        while (j < n) {
            sum += nums[j];
            mp[nums[j]]++;
            if (j - i + 1 == k) {
                if (mp.size() == k)
                    result = max(result, sum);
                sum -= nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};
