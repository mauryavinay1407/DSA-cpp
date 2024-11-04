// problem: https://leetcode.com/problems/string-compression-iii

/*
Approach: Simple simulation
Time Complexity:   O(N)
Space Complexity:  O(1)
*/
class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        int count = 0;
        string comp = "";
        while (i < word.length()) {
            char ch = word[i];
            while (i < word.length() && word[i] == ch && count < 9) {
                count++;
                i++;
            }
            comp = comp + to_string(count) + ch;
            count = 0;
        }
        return comp;
    }
};
