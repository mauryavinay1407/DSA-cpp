// problem:   https://leetcode.com/problems/longest-palindromic-substring/description/

// Approach-1 (Recursive)

class Solution {
public:
    bool isPalindrome(string& s,int i,int j){
       if(i>=j)
       return true;

       if(s[i]!=s[j])
       return false;

       return isPalindrome(s,i+1,j-1);
    }

    string longestPalindrome(string s) {
     int n=s.length();
     int maxLen=0;
     string ans="";
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
          if(isPalindrome(s,i,j)){
            if(j-i+1 > maxLen){
                maxLen=j-i+1;
                ans=s.substr(i,j-i+1);
            }
          }
        }
     }
     return ans;
    }
};


// Approach-2:  (Recursion + Memoization)


class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(string& s,int i,int j){
       if(i>=j)
       return true;

       if(dp[i][j]!=-1)
       return dp[i][j];

       if(s[i]!=s[j])
       return false;

       return dp[i][j] = isPalindrome(s,i+1,j-1);
    }

    string longestPalindrome(string s) {
     memset(dp,-1,sizeof(dp));
     int n=s.length();
     int maxLen=0;
     string ans="";
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
          if(isPalindrome(s,i,j)){
            if(j-i+1 > maxLen){
                maxLen=j-i+1;
                ans=s.substr(i,j-i+1);
            }
          }
        }
     }
     return ans;
    }
};

