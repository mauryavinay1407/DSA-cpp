// problem:  https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

/*
Approach: Backtracking, exploring all possible combination 
Time Complexity: O(N*2^N)
Space Complexity: O(N)
*/

class Solution {
public:
    void splitUnique(string s, unordered_set<string>& st, int i,
                     int& maxCount) {
        if (i == s.length()) {
            maxCount = max(maxCount, (int)st.size());
            return;
        }
        for (int j = i; j < s.length(); j++) {
            string temp = s.substr(i, j - i + 1);
            if (!st.count(temp)) {
                st.insert(temp);
                splitUnique(s, st, j + 1, maxCount);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount = INT_MIN;
        splitUnique(s, st, 0, maxCount);
        return maxCount;
    }
};
