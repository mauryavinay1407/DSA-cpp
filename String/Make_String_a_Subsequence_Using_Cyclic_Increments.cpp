// problem: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments

/*
Approach: Using two pointer 
Time Complexity:    O(M + N)
Space Complexity:   O(1)
*/
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        if (str2.length() > str1.length())
            return false;
        while (i < str2.length()) {
            while (j < str1.length() &&
                   (str2[i] != str1[j] &&
                    str2[i] != (str1[j] - 'a' + 1) % 26 + 'a')) {
                j++;
            }
            if (j < str1.length()) {
                i++;
                j++;
            } else
                break;
        }
        return i == str2.length();
    }
};
