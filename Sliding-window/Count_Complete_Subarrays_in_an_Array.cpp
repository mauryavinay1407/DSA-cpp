//  problem  :  https://leetcode.com/problems/count-complete-subarrays-in-an-array

/*
Approach - Using two pointers and set and hashmap
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int count = st.size();
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        int result = 0;
        while (j < nums.size()) {
            mp[nums[j]]++;
            while (mp.size() == count) {
                result += (n - j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
