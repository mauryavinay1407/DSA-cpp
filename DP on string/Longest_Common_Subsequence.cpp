// problem :  https://leetcode.com/problems/longest-common-subsequence/description/

/*
Approach-1: Recursion (TLE)
Time Complexity:  O(2^m+n)
Space Complexity: O(M + N)   due to recursion stack
*/

class Solution {
public:
    int lcs(string text1,string text2,int i,int j){
        if(i==text1.length() || j==text2.length())
        return 0;
        if(text1[i]==text2[j])
         return 1+lcs(text1,text2,i+1,j+1);
        else
         return max(lcs(text1,text2,i+1,j),lcs(text1,text2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
     return lcs(text1,text2,0,0);
    }
};


/*
Approach-2: Recursion + Memoization
Time Complexity:      O(M*N)
Space Complexity:     O(M*N)
*/

class Solution {
public:
    int dp[1001][1001];
    int lcs(string& text1,string& text2,int i,int j){
        if(i==text1.length() || j==text2.length())
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(text1[i]==text2[j])
         return dp[i][j] = 1+lcs(text1,text2,i+1,j+1);
        else
         return dp[i][j] = max(lcs(text1,text2,i+1,j),lcs(text1,text2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
     memset(dp,-1,sizeof(dp));
     return lcs(text1,text2,0,0);
    }
};

/*
Approach-3: Bottom up
Time Complexity:      O(M*N)
Space Complexity:     O(M*N)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
