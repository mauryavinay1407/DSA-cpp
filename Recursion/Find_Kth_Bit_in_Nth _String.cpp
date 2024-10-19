// problem:  https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1)
            return '0';
        int length = (1 << n) - 1; // pow(2,n)-1
        if (k < ceil(length / 2.0))
            return findKthBit(n - 1, k);
        else if (k == ceil(length / 2.0))
            return '1';
        else {
            char ch = findKthBit(n - 1, length - (k - 1));
            return (ch == '0') ? '1' : '0';
        }
    }
};
