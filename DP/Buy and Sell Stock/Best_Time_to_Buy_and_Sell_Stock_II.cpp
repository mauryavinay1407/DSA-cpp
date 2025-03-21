// leetcode :   https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

// gfg      :   https://www.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

/*
Approach- Using recursion and Memoization
Time Complexity     :  O(N)
Spae Complexity     :  O(N)
*/

class Solution {
public:
    int findMaxProfit(vector<int>& prices, int i, int canBuy,
                      vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;
        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];
        if (canBuy) {
            int taken = findMaxProfit(prices, i + 1, false, dp) - prices[i];
            int skip = findMaxProfit(prices, i + 1, true, dp);
            return dp[i][canBuy] = max(taken, skip);
        } else {
            int taken = prices[i] + findMaxProfit(prices, i + 1, true, dp);
            int skip = findMaxProfit(prices, i + 1, false, dp);
            return dp[i][canBuy] = max(taken, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return findMaxProfit(prices, 0, true, dp);
    }
};
