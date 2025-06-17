// problem  :  https://www.geeksforgeeks.org/problems/coin-piles5152/1

/*
Approach - greedy + prefix sum + sorting + binary search
Time Complexity      :   O(N*logN)
Space Complexity     :   O(1)
*/

class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Sort the array to efficiently group values within range [x, x+k)
        sort(arr.begin(), arr.end());
        
        // Total sum of all elements in the array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        int prefixIdx = 0, prefixSum = 0;
        int minRemove = INT_MAX, removedSum = 0;
        
        for (int i = 0; i < n; i++) {
            // Find the first index where value >= arr[i] + k
            // Elements from this index onward are out of allowed range
            int nextIdx = lower_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();
            
            // Add up all elements before nextIdx that are being skipped (right part)
            while (prefixIdx < nextIdx) {
                removedSum += arr[prefixIdx++];
            }
            
            // Cost to remove all elements to the left of current base (arr[i])
            int left = prefixSum;

            // Cost to reduce right-side elements > arr[i]+k to exactly arr[i]+k
            int right = (totalSum - removedSum) - (n - nextIdx) * (arr[i] + k);
            
            // Update the minimum cost of removing/modifying elements
            minRemove = min(minRemove, left + right);

            // Update prefix sum for next iteration
            prefixSum += arr[i];
        }

        return minRemove;
    }
};
