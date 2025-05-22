// problem : https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

/*
Approach - Using LPS(longest palindromic substring) Recursion + Memoization
Time Complexity        :   O(N^2)
Space Complexity       :   O(N^2)
*/
class Solution {
  public:
    int lps(string& s,int i,int j,vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = 2 + lps(s,i+1,j-1,dp);
        }
        else{
            return dp[i][j] = max(lps(s,i+1,j,dp),lps(s,i,j-1,dp));
        }
    }
    int minDeletions(string s) {
        // code here
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int i = 0;
        int j = s.length()-1;
        return s.length() - lps(s,i,j,dp);
    }
};
