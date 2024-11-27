// problem: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// problem: https://leetcode.com/problems/maximum-subarray

/*
Approach-1: Brute Force(by generating all possible subarray using 3 loops)
Time Complexity:    O(N^3)
Space Complexity:   O(1)
*/
int maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    int result = INT_MIN; // maximum sum
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            result = max(result, sum);
        }
    }
    return result;
}

/*
Approach-2: Better(by generating all possible subarray using 2 loops))
Time Complexity:    O(N^2)
Space Complexity:   O(1)
*/
int maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    int result = INT_MIN; 
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            result = max(result, sum); 
        }
    }
    return result;
}

/*
Approach-3: Optimal (using Kadane's Algorithm)
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
int maxSubarraySum(vector<int> &arr) {
  int result = INT_MIN;
  int prefix = 0;
  for(int i=0;i<arr.size();i++){
      prefix += arr[i];
      result = max(result,prefix);
      if(prefix < 0)
          prefix = 0;
  }
  return result;
}

/*
Approach-4: Optimal (using Kadane's Algorithm)
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
    int maxSubArray(vector<int>& nums) {
    int currentSum=0;
    int ans=INT_MIN;
    for(int num:nums){
        currentSum=max(num,num+currentSum);
        ans=max(ans,currentSum);
    }
    return ans;
    }
