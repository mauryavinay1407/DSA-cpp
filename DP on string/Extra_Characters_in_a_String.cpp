// problem:  https://leetcode.com/problems/extra-characters-in-a-string/description/

/*
Approach-1: Recursion
T.C - O(2^n*n*n)
S.C - O(m * k)
where m=total number of characters in dictionary words
*/

class Solution {
public:
      int findMinLen(int i,string s,unordered_set<string>& st){
        if(i>=s.length()){
            return 0;
        }
        int result=1+findMinLen(i+1,s,st);
        for(int j=i;j<s.length();j++){
            if(st.count(s.substr(i,j-i+1))){
             result=min(result,findMinLen(j+1,s,st));
            }
        }
        return result;
      }
      int minExtraChar(string s, vector<string>& dict) {
      unordered_set<string> st(begin(dict),end(dict));
      return findMinLen(0,s,st);
    } 
};


/*
Approach-2: Recursion + Memoization
//T.C : O(n^3)
//S.C : O(m+n)
*/

class Solution {
public:
      int dp[51];
      int findMinLen(int i,string s,unordered_set<string>& st){
        if(i>=s.length()){
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int result=1+findMinLen(i+1,s,st);
        for(int j=i;j<s.length();j++){
            if(st.count(s.substr(i,j-i+1))){
             result=min(result,findMinLen(j+1,s,st));
            }
        }
        return dp[i]=result;
      }
      int minExtraChar(string s, vector<string>& dict) {
      unordered_set<string> st(begin(dict),end(dict));\
      memset(dp,-1,sizeof(dp));
      return findMinLen(0,s,st);
    } 
};

/*
Approach-3 Bottom Up
T.C : O(n^3)
S.C : O(n)
*/

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict), end(dict));
        int n = s.length();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];
            for (int j = i; j < n; j++) {
                if (st.count(s.substr(i, j - i + 1)))
                    dp[i] = min(dp[i], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
