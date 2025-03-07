// problem : https://leetcode.com/problems/closest-prime-numbers-in-range

/*
Approach-1: Brute force
Time Complexity    :  O((R-L) * sqrt(R))
Space Complexity   :  O(1)
*/

class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int first = -1;
        int second = -1;
        int mini = INT_MAX;
        vector<int> result(2, -1);
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (first == -1) {
                    first = i;
                    continue;
                } else if (second == -1) {
                    second = i;
                } else {
                    first = second;
                    second = i;
                }
                if (mini > second - first) {
                    mini = second - first;
                    result[0] = first;
                    result[1] = second;
                }
            }
        }
        return result;
    }
};

/*
Approach-2: Using Sieve of Eratosthenes
Time Complexity    :  O(Rlog(log(R)) + (R-L))
Space Complexity   :  O(R)
*/

class Solution {
public:
    vector<bool> sieveHelper(int right) {
        vector<bool> isPrime(right+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i*i <= right; i++) {
            if(isPrime[i] == true) {
                for(int j = 2; i*j <= right; j++) {
                    isPrime[i*j] = false;
                }
            }
        }

        return isPrime;
    }


    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveHelper(right);

        vector<int> primes;
        for(int num = left; num <= right; num++) {
            if(isPrime[num] == true) {
                primes.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];

            if(diff < minDiff) {
                minDiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }

        return result;
    }
};
