// gfg      :  https://www.geeksforgeeks.org/problems/edit-distance3702/1
// leetcode :  https://leetcode.com/problems/edit-distance

/*
Approach- Using Recursion + Memo
Time Complexity      :  O(M*N)
Space Complexity     :  O(M*N)
*/

class Solution {
public:
    int dp[501][501];
    int m, n;
    int findDist(string& w1, string& w2, int i, int j) {
        if (i == m)
            return n - j;
        if (j == n)
            return m - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (w1[i] == w2[j])
            return dp[i][j] = findDist(w1, w2, i + 1, j + 1);

        else {
            int insertChar = 1 + findDist(w1, w2, i, j + 1);
            int deleteChar = 1 + findDist(w1, w2, i + 1, j);
            int replaceChar = 1 + findDist(w1, w2, i + 1, j + 1);

            return dp[i][j] = min({insertChar, deleteChar, replaceChar});
        }
        return -1;
    }
    int minDistance(string w1, string w2) {
        m = w1.length();
        n = w2.length();
        memset(dp, -1, sizeof(dp));
        return findDist(w1, w2, 0, 0);
    }
};
