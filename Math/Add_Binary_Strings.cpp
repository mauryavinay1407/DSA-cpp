// problem: https://www.geeksforgeeks.org/problems/add-binary-strings3805/1

/*
Approach: Simple start adding from the last bit
Time Complexity:    O(max(a.size,b.size))
Space Complexity:   O(max(a.size,b.size))
*/

class Solution {
  public:
    string addBinary(string& a, string& b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }
            result += (sum % 2) + '0'; // Add the current binary digit to result
            carry = sum / 2; // Compute carry
        }
        reverse(result.begin(), result.end()); 
        int it = 0;
        while (it < result.size() && result[it] == '0') {
            it++;
        }
        result = result.substr(it);
        if (result.empty()) {
            result = "0";  
        }
        return result;
    }
};
