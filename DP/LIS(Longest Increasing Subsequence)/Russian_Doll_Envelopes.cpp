// problem:  https://leetcode.com/problems/russian-doll-envelopes

/*
Approach-1: Recursion + Memoization
Time Complexity:    O(N^2)
Space Complexity:   O(N^2)
*/

class Solution {
public:
    int findMaxEnvelopes(vector<vector<int>>& env,int i,int mini,vector<vector<int>>& dp){
        if(i >= env.size())
            return 0;
        if(mini != -1 && dp[i][mini] != -1)
            return dp[i][mini];
        int taken=0;
        if(mini==-1 || (env[mini][0]<env[i][0] && env[mini][1]<env[i][1]))
            taken = 1 + findMaxEnvelopes(env,i + 1, i,dp);
        int skip = findMaxEnvelopes(env,i + 1,mini,dp);

        if(mini != -1 )
            dp[i][mini] = max(taken,skip);
        return max(taken,skip);
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(begin(env),end(env));
        int n = env.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return findMaxEnvelopes(env,0,-1,dp);
    }
};

/*
Approach-2: Using patience sorting (Binary search + LIS)
Time Complexity:    O(N*logN)
Space Complexity:   O(N)
*/

class Solution {
public:
    static bool myCustomComparator(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), myCustomComparator);
        int n = env.size();
        vector<int> LIS;
        for (auto& e : env) {
            int height = e[1];
            auto lb = lower_bound(LIS.begin(), LIS.end(), height);
            if (lb == LIS.end())
                LIS.push_back(height);
            else
                *lb = height;
        }
        return (int)LIS.size();
    }
};
