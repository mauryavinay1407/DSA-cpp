// problem : https://leetcode.com/problems/minimum-time-to-repair-cars

/*
Approach- Using Binary Search
Time Complexity   : O(n * log(maxRank * cars * cars))
Space Complexity  : O(1)
*/

class Solution {
public:
    bool check(vector<int>& ranks, int k, long long time) {
        for (auto& r : ranks) { 
            k -= (long long)sqrt(time / r);
            if (k <= 0) {
                return true;
            }
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long result = -1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(ranks, cars, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
