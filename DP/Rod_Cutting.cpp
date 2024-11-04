// problem : https://www.geeksforgeeks.org/problems/rod-cutting0840/1

/*
Approach-1: Recursion + Memoization
Time Complexity:    O(N^2)
Space Complexity:   O(N)
*/
 
class Solution{
  public:
    int N;
    int dp[1001];
    int findCutRod(int price[],int n){
        if(n <= 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int result=0;
        for(int i=0;i<n;i++)
            result = max(result, price[i] + findCutRod(price,n - (i+1)));
        
        return dp[n] = result;
    }
    int cutRod(int price[], int n) {
        N = n;
        memset(dp,-1,sizeof(dp));
        return findCutRod(price,n);
    }
};

/*
Approach-2:  Bottom up
Time Complexity:    O(N^2)
Space Complexity:   O(N)
*/
 
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = max(dp[i], price[j] + dp[i - (j + 1)]);
            }
        }

        return dp[n];
    }
};
