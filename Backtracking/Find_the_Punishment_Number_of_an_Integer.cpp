// problem : https://leetcode.com/problems/find-the-punishment-number-of-an-integer

/*
Approach - Using backtracking
Time Complexity    : O(2^n)
Space Complexity   : O(n^2)
*/

class Solution {
public:
    bool check(string str, int i, int sum, int n) {
        if (i == str.length()) {
            return sum == n;
        }
        if (sum > n) {
            return false;
        }
        for (int j = i; j < str.length(); j++) {
            string sub = str.substr(i, j - i + 1);
            int num = stoi(sub);
            if (check(str, j + 1, sum + num, n)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            int squared = i * i;
            string num = to_string(squared);
            if (check(num, 0, 0, i))
                result += squared;
        }
        return result;
    }
};
