// problem:  https://www.geeksforgeeks.org/problems/minimal-cost/1

/*
Time Complexity: O(n*k)
Space Complexity: O(n)
*/

class Solution {
  public:
    int dp[10000];  
    int findCost(int i, int pre, int k, vector<int>& arr) {
    if (i == arr.size()) 
        return 0;   
    
    if (dp[i] != -1) 
        return dp[i];  
        
    int minCost = INT_MAX;

    for (int j = i; j < i + k; j++) {
        if (j < arr.size()) {
            int newCost = abs(pre - arr[j]);  
            minCost = min(minCost, newCost + findCost(j + 1, arr[j], k, arr));  
    }
    }
    return dp[i] = minCost; 
}

int minimizeCost(int k, vector<int>& arr) {
    if (arr.size() == 1)
        return 0;  

    memset(dp, -1, sizeof(dp)); 
    return findCost(1, arr[0], k, arr);  
}
};
