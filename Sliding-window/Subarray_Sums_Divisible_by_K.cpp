// problem:   https://leetcode.com/problems/subarray-sums-divisible-by-k/


/*
Approach-1: Brute Force
Time Complexity: O(n^2)
Space Complexity:  O(1)
*/

int subarraysDivByK(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum % k == 0) {
                count++;
            }
        }
    }

    return count;
}


/*
Approach-2: Optimal using prefix sum
Time Complexity: O(n)
Space Complexity:  O(min(n, k))
*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end())
                count += mp[rem];
                
            mp[rem]++;
        }
        return count;
    }
};
