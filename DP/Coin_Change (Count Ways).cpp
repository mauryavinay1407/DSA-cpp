// problem:  https://www.geeksforgeeks.org/problems/coin-change2448/1

/*
Approach-1: Recursion + Memoization
Time Complexity:    O(N*sum)
Space Complexity:   O(N*sum)
*/

class Solution {
  public:
    long long int dp[1001][1001];
    long long int findCount(vector<int>& coins,int remainingSum,int i){
        if(remainingSum == 0)
            return 1 ;
        if(i >= coins.size() || remainingSum < 0)
            return 0;
            
        if(dp[i][remainingSum] != -1)
            return dp[i][remainingSum];
            
        long long int taken = findCount(coins,remainingSum - coins[i],i);
        long long int skip = findCount(coins,remainingSum,i+1);
        
        return dp[i][remainingSum] = taken + skip;
    }
    long long int count(vector<int> coins, int sum) {
        memset(dp,-1,sizeof(dp));
        return findCount(coins,sum,0);
    }
};

/*
Approach-2: Bottom up
Time Complexity:    O(N*sum)
Space Complexity:   O(sum)
*/

class Solution {
  public:
    long long int count(vector<int> coins, int sum) {
        vector<long long int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int j = coin; j <= sum; ++j) {
                dp[j] += dp[j - coin];
            }
        }
        return dp[sum];
    }
};
