// problem: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

/*
Approach-1 : Bottom up (same as LIS)
Time Complexity: O(N^2)
Space Complexity: O(N)
*/
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(obs[j] <= obs[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
};

/*
Approach-2: Using Binary Search (Patience sorting)
Time Complexity:       O(N*logN)
Space Complexity:      O(N)
*/
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        vector<int> LIS;
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(LIS.begin(), LIS.end(), obs[i]) - LIS.begin();
            if (idx == LIS.size())
                LIS.push_back(obs[i]);
            else
                LIS[idx] = obs[i];

            result[i] = idx + 1;
        }
        return result;
    }
};
