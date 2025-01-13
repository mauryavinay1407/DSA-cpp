// problem  :  https://leetcode.com/problems/minimum-length-of-string-after-operations

/*
Approach: By counting the occurence of each letter
Time Complexity    :   O(N)
Space Complexity   :   O(1)
*/
class Solution {
public:
    int minimumLength(string s) {
        vector<int> counts(26, 0);
        int result = 0;
        for (auto& l : s)
            counts[l - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 2) {
                result += (counts[i] % 2 == 0) ? 2 : 1;
            } else
                result += counts[i];
        }
        return result;
    }
};
