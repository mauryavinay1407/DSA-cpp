// problem: https://leetcode.com/problems/count-the-number-of-fair-pairs

/*
Approach-1: Brute force
Time Complexity: O(N^2)  TLE
Space Complexity: O(1)
*/
class Solution {
public:
    bool isValid(int num, int lower, int upper) {
        return lower <= num && num <= upper;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (isValid(nums[i] + nums[j], lower, upper))
                    count++;
            }
        }
        return count;
    }
};

/*
Approach-2: sorting
Time Complexity: O(N*LogN) 
Space Complexity: O(1)
*/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums),end(nums));
        long long count = 0;
        for(int i = 0 ; i<nums.size();i++){
            int x = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin() - i - 1;
            int y = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin() - i - 1;
            count += (y - x);
        }
        return count;
    }
};
