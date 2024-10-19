// problem : https://www.geeksforgeeks.org/problems/minimum-steps1159/1

/*
Approach:1- Recursion + Memoization
Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution {
  public:
    int dp[100001];
    int findMoves(int n,int p,int q){
        if(n<0)
            return -1;
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
            
        int stepP=findMoves(n-p,p,q);
        int stepQ=findMoves(n-q,p,q);
        
        if(stepP==-1 && stepQ==-1)
            return dp[n] = -1;
        if(stepP==-1)
            return dp[n] = 1 + stepQ;
        if(stepQ==-1)
            return dp[n] = 1 + stepP;
            
        return dp[n] = min(stepP,stepQ) + 1;
    }
    int moves(int n, int p, int q) {
       memset(dp,-1,sizeof(dp));
       return findMoves(n,p,q);
    }
};

/*
Approach:2- Bottom-up
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    int moves(int n, int p, int q) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            if(i>=p && dp[i-p]!=-1)
                dp[i] = dp[i-p] + 1;
            if(i>=q && dp[i-q]!=-1){
                if(dp[i]==-1)
                    dp[i] = dp[i-q] + 1;
                else
                    dp[i]= min(dp[i],dp[i-q]+1);
            }
        }
        return dp[n];
    }
};
