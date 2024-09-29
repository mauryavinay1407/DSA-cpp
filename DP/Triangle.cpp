// problem:  https://leetcode.com/problems/triangle/description/

/*
Approach-1: Recursion + Memoization
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int dp[200][200];
    int findminimumTotal(vector<vector<int>>& triangle,int i,int j){
        if(i==triangle.size()-1)
         return triangle[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
         return dp[i][j] = triangle[i][j]+min(findminimumTotal(triangle,i+1,j),findminimumTotal(triangle,i+1,j+1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
     memset(dp,-1,sizeof(dp));
     return findminimumTotal(triangle,0,0);
    }
};

/*
Approach-2: Bottom up
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp = triangle[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}

};
