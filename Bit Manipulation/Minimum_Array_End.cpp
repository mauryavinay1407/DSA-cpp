// problem: https://leetcode.com/problems/minimum-array-end

/*
Approach: Next number will be number + 1 OR x  i.e after 7 if we take 8 them 8 | 7 = 15 which will be next number
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1)
            return x;
        long long result = x;
        int t = n - 1;
        while (t) {
            result = (result + 1) | x;
            t--;
        }
        return result;
    }
};
