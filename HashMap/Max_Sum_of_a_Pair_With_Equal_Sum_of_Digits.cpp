//  problem : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

/*
Approach-1: Brute force
Time Complexity    : O(n^2 * m), m = number of digits
Space Complexity   : O(1)
*/
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        for(int i = 0; i < n; i++) {
            int digitSumi = getDigitSum(nums[i]);

            for(int j = i+1; j < n; j++) {
                int digitSumj = getDigitSum(nums[j]);

                if(digitSumi == digitSumj) {
                    result = max(result, nums[i] + nums[j]);
                }
            }
        }

        return result;
    }
};

/*
Approach-2: better using hashmap
Time Complexity    : O(n*m), m = number of digits
Space Complexity   : O(n)
*/
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> digits;
        for (auto& num : nums) {
            int temp = num;
            long long sum = 0;
            while (temp) {
                int t = temp % 10;
                sum += t;
                temp /= 10;
            }
            digits.push_back(sum);
        }

        unordered_map<int, int> mp;
        int result = -1;
        for (int i = 0; i < digits.size(); i++) {
            if (mp.count(digits[i])) {
                result = max(result, nums[i] + mp[digits[i]]);
                mp[digits[i]] = max(mp[digits[i]], nums[i]);
            } else {
                mp[digits[i]] = nums[i];
            }
        }
        return result;
    }
};
