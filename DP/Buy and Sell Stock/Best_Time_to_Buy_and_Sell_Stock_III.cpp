// leetcode   :   https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// gfg        :   https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

/*
Approach - Using Recursion and Memoization
Time Complexity     :   O(N)
Space Complexity    :   O(N)
*/

class Solution {
public:
    int findMaxProfit(vector<int>& prices, int i, int k, bool canBuy,
                      vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || k == 2) {
            return 0;
        }
        if (dp[i][k][canBuy] != -1) {
            return dp[i][k][canBuy];
        }
        if (canBuy) {
            int taken = findMaxProfit(prices, i + 1, k, false, dp) - prices[i];
            int skip = findMaxProfit(prices, i + 1, k, true, dp);
            return dp[i][k][canBuy] = max(taken, skip);
        } else {
            int taken =
                findMaxProfit(prices, i + 1, k + 1, true, dp) + prices[i];
            int skip = findMaxProfit(prices, i + 1, k, false, dp);
            return dp[i][k][canBuy] = max(taken, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));
        return findMaxProfit(prices, 0, 0, true, dp);
    }
};
