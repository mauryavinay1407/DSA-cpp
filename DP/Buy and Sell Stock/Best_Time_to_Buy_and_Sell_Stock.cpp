// problem   :  https://leetcode.com/problems/best-time-to-buy-and-sell-stock

/*
Approach-  Using recursion
Time Complexity      :  O(N) 
Space Complexity     :  O(1)
*/

class Solution {
public:
    int findMaxProfit(vector<int>& prices,int i,int minPrice,int maxProfit){
        if(i >= prices.size())
            return maxProfit;
        minPrice = min(minPrice,prices[i]);
        int profit = prices[i] - minPrice;
        return findMaxProfit(prices,i + 1,minPrice,max(profit,maxProfit));
        
    }
    int maxProfit(vector<int>& prices) {
        return findMaxProfit(prices,0,INT_MAX,INT_MIN);
    }
};
