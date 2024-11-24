// problem: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

/*
Approach: Using sliding window
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> counts(3, 0);
        int n = s.length();
        for (char c : s)
            counts[c - 'a']++;

        for (int count : counts)
            if (count < k)
                return -1;

        int i = 0, j = 0;
        int result = n;
        while (j < n) {
            counts[s[j] - 'a']--;
            while (counts[0] < k || counts[1] < k || counts[2] < k)
                counts[s[i++] - 'a']++;
            result = min(result, n - (j - i + 1));
            j++;
        }
        return result;
    }
};
