// problem  : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i

/*
Approach - By checking the binary bits linearly
Time Complexity     :  O(N)
Space Complexity    :  O(1)
*/
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int current;
        vector<string> result;
        for (int i = 0; i < groups.size(); i++) {
            if (i == 0 || groups[i] != current) {
                current = groups[i];
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
