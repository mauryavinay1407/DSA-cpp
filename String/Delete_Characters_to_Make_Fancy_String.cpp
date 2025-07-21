// problem  :  https://leetcode.com/problems/delete-characters-to-make-fancy-string

/*
Approach - Using Greedy
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/
class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 2)
            return s;
        for (int i = 2; i < s.length(); i++) {
            if ((s[i - 1] == s[i]) && (s[i - 2] == s[i]))
                s[i - 2] = '$';
        }

        string result = "";
        for (auto& str : s)
            if (str != '$')
                result += str;
        return result;
    }
};
