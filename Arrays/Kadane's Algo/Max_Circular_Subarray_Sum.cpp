// problem: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

/*
Approach-1: Brute force(by considering every element as the beginning of the subarray)
Time Complexity:    O(N^2)
Space Complexity:   O(1)
*/
class Solution {
public:
int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int res = arr[0];
    
    // Subarray that starts with index i
    for(int i = 0; i < n; i++) {
        int currSum = 0;
        
        // Considering all possible endpoints of the Subarray that begins with index i
     for(int j = 0; j < n; j++) {
        // Circular index
        int idx = (i + j) % n;
        currSum = currSum + arr[idx];            
        res = max(res, currSum);
        }
    }    
    return res;
}
};
/*
Approach-2: Better (Using Prefix and Suffix Sum)
Time Complexity:    O(N)
Space Complexity:   O(N)
*/
class Solution {
public:
int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int suffixSum = arr[n - 1];
    
    // maxSuffix array to store the value of maximum suffix occured so far.
    vector<int> maxSuffix(n + 1, 0);
    maxSuffix[n - 1] = arr[n - 1];
    
    for(int i = n - 2; i >= 0; i--) {
        suffixSum = suffixSum + arr[i];
        maxSuffix[i] = max(maxSuffix[i + 1], suffixSum);
    }
    
    // circularSum is Maximum sum of circular subarray
    int circularSum = arr[0];
    
    // normalSum is Maxium sum subarray considering the array is non-circular
    int normalSum = arr[0];
    
    int currSum = 0;
    int prefix = 0;
    for(int i = 0; i < n; i++) {
        // Kadane's algorithm
        currSum = max(currSum + arr[i], arr[i]);
        normalSum = max(normalSum, currSum);
      
        // Calculating maximum Circular Sum
        prefix = prefix + arr[i];
        circularSum = max(circularSum, prefix + maxSuffix[i+1]);
    }
    return max(circularSum, normalSum);
}
};

/*
Approach-3: Optimal (Using Kadane's Algorithm)
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
int circularSubarraySum(vector<int> &arr) {
    int totalSum = 0;
    int currMaxSum = 0, currMinSum = 0;
    int maxSum = arr[0], minSum = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        // Kadane's to find maximum sum subarray
        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum);

        // Kadane's to find minimum sum subarray
        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum);

        // Sum of all the elements of input array
        totalSum = totalSum + arr[i];
    }
    // If the minimum subarray is equal to total Sum then we just need to return normalSum
    if (minSum == totalSum)
        return maxSum;

    return max(maxSum, totalSum - minSum);
}
};
