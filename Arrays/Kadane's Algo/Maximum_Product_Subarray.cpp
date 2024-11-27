// problem: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

/*
Approach-1: Brute Force(by generating all possible subarray using 3 loops)
Time Complexity:    O(N^3)
Space Complexity:   O(1)
*/
class Solution {
public:
int maxSubarrayProduct(vector<int>& nums) {
   int n = nums.size();
   int result = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);
        }
    }
    return result;
}
};
/*
Approach-2: Better(by generating all possible subarray using 2 loops))
Time Complexity:    O(N^2)
Space Complexity:   O(1)
*/
class Solution {
public:
int maxSubarrayProduct(vector<int>& nums) {
    int n = nums.size();
    int result = INT_MIN; 
    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = i; j < n; j++) {
            product *= nums[j];
            result = max(result, product); 
        }
    }
    return result;
}
};
/*
Approach-3: Optimal (using Kadane's Algorithm)
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
    int maxSubarrayProduct(vector<int> &nums) {
        long long result = INT_MIN;
        long long product = 1;

        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            result = max(product, result);
            if (product == 0) product = 1; 
        }

        product = 1; 

        for (int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            result = max(product, result);
            if (product == 0) product = 1; 
        }

        return (int)result; 
    }
};
/*
Approach-4: Optimal (using Kadane's Algorithm)
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
  int maxSubarrayProduct(vector<int> &nums) {
      int n = nums.size();
      int prefix = 1, suffix = 1, result = INT_MIN;
      for(int i = 0; i < n; i++){
          if(prefix == 0)
              prefix = 1;
          if(suffix == 0)
              suffix = 1;
          prefix *= nums[i];
          suffix *= nums[n - i - 1];
          result = max(result, max(prefix, suffix));
      }
      return result;
}  
};
