// problem : https://leetcode.com/problems/thousand-separator

/*
Approach - simple dividing by 10
Time Complexity   :  O(logN)    
Space Complexity  :  O(1)
*/

/*
Why time is O(logN) ???
Loop Iterations: The while loop while (n > 0) iterates until n becomes 0. In each iteration, n is divided by 10, which reduces the number of digits by one. The number of times you can divide a number n by 10 until it becomes 0 is proportional to the number of digits in n.

Logarithmic Relationship: The number of digits in a number n is given by log10(n), which represents the logarithm of n to the base 10. This means that the loop runs approximately log10(n) times.
*/

class Solution {
public:
    string thousandSeparator(int n) {
        if (n < 1000)
            return to_string(n);

        int count = 0;
        string result;
        while (n > 0) {
            if (count == 3) {
                result += '.';
                count = 0;
            }
            result += to_string(n % 10);
            n /= 10;
            count++;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
