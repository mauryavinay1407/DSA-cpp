// problem : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

/*
Approach-1 : Brute Force
Time Complexity:   O(m*n*t)    m: Traversing the columns of the words matrix.
                               t: Processing each character of the target string.
                               n: Iterating through the rows of the words matrix at each step.
Space Complexity:  O(m*t)
*/

class Solution {
public:
    int n;
    long long dp[1000][1000];
    int MOD = 1e9 + 7;

    int findWays(vector<string>& words, int j, int k, string target) {
        if (k >= target.length())
            return 1;
        if (j >= words[0].length())  
            return 0;

        if (dp[j][k] != -1)
            return dp[j][k];

        long long result = 0;

        int count = 0;
        for (int x = 0; x < n; ++x) {
            if (words[x][j] == target[k]) {
                count++;
            }
        }
        result = (result + (1LL * count * findWays(words, j + 1, k + 1, target)) % MOD) % MOD;
        result = (result + findWays(words, j + 1, k, target)) % MOD;

        return dp[j][k] = result;
    }

    int numWays(vector<string>& words, string target) {
        n = words.size();
        memset(dp, -1, sizeof(dp));
        return findWays(words, 0, 0, target);
    }
};

/*
Approach-2 : Optimal dp(recursion + memoization)
Time Complexity:   O(n*k)
Space Complexity:  O(n*k)
*/
class Solution {
public:
    int n, k;
    int dp[1001][1001];
    const long long MOD = 1e9 + 7;

    int findWays(vector<vector<int>>& freq, int i, int j, string& target) {
        if (i == k)
            return 1;
        if (j == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int skip = findWays(freq, i, j + 1, target);
        int count = freq[target[i] - 'a'][j];
        int taken = (count * (findWays(freq, i + 1, j + 1, target)%MOD)) % MOD;

        return dp[i][j] = (skip + taken) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        n = words[0].size();
        k = target.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (auto& w : words) {
                freq[w[i] - 'a'][i]++;
            }
        }
        return findWays(freq, 0, 0, target);
    }
};
