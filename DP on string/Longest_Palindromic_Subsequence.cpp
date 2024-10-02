// problem: https://leetcode.com/problems/longest-palindromic-subsequence

/*
Approach-1: Recursion + Memoization
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int dp[1001][1001];
    int findPalindrome(int i,int j,string& s){
       if(i>j)
       return 0; 
       if(i==j)
        return 1;
       if(dp[i][j]!=-1)
       return dp[i][j]; 

       if(s[i]==s[j])
       return dp[i][j] = 2 + findPalindrome(i+1,j-1,s);
       else
       return dp[i][j] = max(findPalindrome(i+1,j,s),findPalindrome(i,j-1,s));  
    }
    int longestPalindromeSubseq(string s) {
       memset(dp,-1,sizeof(dp));
       return findPalindrome(0,s.length()-1,s);
    }
};

