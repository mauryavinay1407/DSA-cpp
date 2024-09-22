// problem:  https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

/*
Approach-1: Brute Force
Time Complexity: O(n^3) 
Space Complexity: O(n) 
*/

int maxSubarrayLength(vector<int>& nums, int k) {
    int maxLen = 0; // Initialize the maximum length to 0
    for (int i = 0; i < nums.size(); i++) {
        unordered_map<int, int> mp; // Reset the frequency map for each subarray starting at i
        for (int j = i; j < nums.size(); j++) {
            mp[nums[j]]++; // Increment the frequency of the current element
            bool valid = true;
            // Check if any element occurs more than k times
            for (auto& entry : mp) {
                if (entry.second > k) {
                    valid = false;
                    break;
                }
            }
            // If valid, update maxLen with the current subarray length
            if (valid) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                break; // If not valid, break the inner loop early
            }
        }
    }
    return maxLen;
}


/*
Approach-2 using sliding window
Time Complexity: O(n) 
Space Complexity: O(n) 
*/


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int maxLen=INT_MIN;
        while(j<nums.size()){
          mp[nums[j]]++;
          while(mp[nums[j]]>k){
            mp[nums[i]]--;
            i++;
          }
          maxLen=max(maxLen,j-i+1);
          j++;
        }
        return maxLen;
    }
};
