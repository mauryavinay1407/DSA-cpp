// problem : https://leetcode.com/problems/count-largest-group

/*
Approach - Using hashmap
Time Complexity    : O(N*logN)
Space Complexity   : O(logN)
*/
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;

        int maxSize = 0;
        int count = 0;

        for (int num = 1; num <= n; num++) {
            int sum = 0;
            int t = num;
            while (t) {
                sum += t % 10;
                t /= 10;
            }
            mp[sum]++;
            if (mp[sum] == maxSize) {
                count++;
            } else if (mp[sum] > maxSize) {
                maxSize = mp[sum];
                count = 1;
            }
        }
        return count;
    }
};
