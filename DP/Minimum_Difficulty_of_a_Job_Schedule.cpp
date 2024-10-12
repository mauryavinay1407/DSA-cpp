// problem : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

/*
Approach-1: Recusrion + Memoization
Time Complexity: O(N^2*d)
Space Complexity: O(301*11) ~ O(1)   or O(N*d)
*/

class Solution {
public:
    int dp[301][11];
    int findminDifficulty(vector<int>& jobs, int d, int i) {
        if (d == 1) {
            return *max_element(jobs.begin() + i, jobs.end());
        }
        if(dp[i][d]!=-1)
        return dp[i][d];
        int minDifficulty = INT_MAX;
        int maxi = INT_MIN;
        for (int j = i; j <= jobs.size() - d; j++) {
            maxi = max(maxi, jobs[j]);
            minDifficulty = min(minDifficulty,
                                maxi + findminDifficulty(jobs, d - 1, j + 1));
        }
        return dp[i][d] = minDifficulty;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        if (jobs.size() < d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return findminDifficulty(jobs, d, 0);
    }
};


/*
Approach-2: Bottom up
Time Complexity: O(N^2*d)
Space Complexity: O(N*d)
*/
class Solution {
public:
    int dp[301][11];
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        if (n < d)
            return -1;

        vector<vector<long long>> dp(n + 1,vector<long long>(d + 1, LLONG_MAX));

        for (int i = 0; i < n; i++) {
            dp[i][1] = *max_element(jobs.begin() + i, jobs.end());
        }

        for (int day = 2; day <= d; day++) {
            for (int i = 0; i <= n - day; i++) {
                int maxi = 0;
                for (int j = i; j <= n - day; j++) {
                    maxi = max(maxi, jobs[j]);
                    dp[i][day] = min(dp[i][day], maxi + dp[j + 1][day - 1]);
                }
            }
        }

        return dp[0][d];
    }
};
