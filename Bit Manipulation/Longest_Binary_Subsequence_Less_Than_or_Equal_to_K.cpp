// problem : https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k

/*
Approach-1 :  Using recursion (TLE)
Time Complexity       :  O(2^N)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int find(string& s, int i, int n, int k) {
        if (i < 0) {
            return 0;
        }

        int value = (s[i] - '0') ? 1LL << (n - i - 1) : 0;

        int taken = 0;
        if (value <= k) {
            taken = 1 + find(s, i - 1, n, k - value);
        }
        int skip = find(s, i - 1, n, k);

        return max(taken, skip);
    }
    int longestSubsequence(string s, int k) {
        int n = s.length();

        return find(s, n - 1, n, k);
    }
};
/*
Approach-2 :  Using simple bit manupulation
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();

        int binaryValue = 1;
        int result = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                result++;
            }
            else if(binaryValue <= k){
                result++;
                k -= binaryValue;
            }
            if(binaryValue <= k){
                binaryValue <<= 1;
            }
        }
        return result;
    }
};
