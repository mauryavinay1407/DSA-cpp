// problem :  https://leetcode.com/problems/longest-common-subsequence/description/

/*
Approach-1: Recursion
TLE
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
