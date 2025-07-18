// problem  : https://www.geeksforgeeks.org/problems/lcm-triplet1501/1

/*
Approach - Using Mathematical Greedy Optimization
Time Complexity      :  O(1)
Space Complexity     :  O(1)
*/
class Solution {
public:
    int lcmTriplets(int n) {
        // If n is less than 3, the maximum LCM is just n itself
        if(n < 3) return n;
        
        int result;

        // Case 1: If n is odd, use (n, n-1, n-2)
        // These are consecutive numbers and usually co-prime, so their LCM is maximized
        if(n % 2 != 0){
            result = n * (n - 1) * (n - 2);
        }

        // Case 2: If n is even but not divisible by 3
        // Use (n, n-1, n-3) to avoid two even numbers (like n and n-2)
        else if(n % 3 != 0){
            result = n * (n - 1) * (n - 3);
        }

        // Case 3: If n is divisible by both 2 and 3 (i.e., divisible by 6)
        // Use (n-1, n-2, n-3) to avoid common divisors
        else{
            result = (n - 1) * (n - 2) * (n - 3);
        }

        return result;
    }
};
