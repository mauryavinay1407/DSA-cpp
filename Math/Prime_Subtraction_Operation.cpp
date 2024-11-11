// problem: https://leetcode.com/problems/prime-subtraction-operation

/*
Approach: using Sieve of Eratosthenes
Time Complexity:     O(n*m), where n is the size of the input vector and m is up to 1000. The sieve operation runs in O(mlog(log(m))).
Space Complexity:    O(n)
*/

class Solution {
public:
    bool isPrime[1000];
    void generatePrimes() {
        fill(isPrime, isPrime + 1000, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p * p < 1000; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i < 1000; i += p) {
                    isPrime[i] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        generatePrimes();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                for (int j = 2; j < nums[i]; j++) {
                    if (isPrime[j] && (nums[i] - j) < nums[i + 1]) {
                        nums[i] -= j;
                        break;
                    }
                }
                if (nums[i] >= nums[i + 1])
                    return false;
            }
        }
        return true;
    }
};
