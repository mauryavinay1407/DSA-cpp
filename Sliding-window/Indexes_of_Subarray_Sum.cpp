// problem : https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

/*
Approach-1: Brute Force
Time Complexity    : O(N^2(
Space Complexity   : O(1)
*/
class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {

        int n = arr.size();
    
        for (int i = 0; i < n; i++) {
            int current_sum = 0;
            for (int j = i; j < n; j++) {
                current_sum += arr[j];
                if (current_sum == target) {
                    return {i + 1, j + 1}; // 1-based indices
                }
            }
        }
    
        return {-1};    
    }
};
/*
Approach-1: Brute Force
Time Complexity    : O(N^2(
Space Complexity   : O(1)
*/
class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int start = 0, current_sum = 0;

        for (int end = 0; end < n; end++) {
        // Add the current element to the current sum
            current_sum += arr[end];
    
            // Shrink the window from the left if the current sum exceeds the target
            while (current_sum > target && start <= end) {
                current_sum -= arr[start];
                start++;
            }
    
            // Check if we found the target sum
            if (current_sum == target) {
                return {start + 1, end + 1}; // 1-based indices
            }
        }

        // If no subarray is found, return [-1]
        return {-1};
    }
};
