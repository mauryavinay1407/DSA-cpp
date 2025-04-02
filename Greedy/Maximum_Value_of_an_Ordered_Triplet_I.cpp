// problem : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i

/*
Approach - 1: Brute Force
Time Complexity    :  O(n^3)
Space Complexity   :  O(1)
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    result = max(result, (long long)(nums[i] - nums[j])*nums[k]);
                }
            }
        }

        return result;
    }
};

/*
Approach - 2: Better using extra space
Time Complexity    :  O(n)
Space Complexity   :  O(n)
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 1;
        bool flag = false;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(nums[i], left[i - 1]);
        }
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(nums[i], right[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            long long t = (long long)(left[i - 1] - nums[i]) * right[i + 1];
            if (result < t) {
                result = t;
                flag = true;
            }
        }
        return flag ? result : 0;
    }
};
/*
Approach - 3: Optimal without space
Time Complexity    :  O(n)
Space Complexity   :  O(1)
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        long long maxDiff = 0;
        long long maxi = 0;

        for (int k = 0; k < n; k++) {
            result = max(result, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxi - nums[k]);
            maxi = max(maxi, (long long)nums[k]);
        }
        return result;
    }
};
