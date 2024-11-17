// problem:  https://leetcode.com/problems/first-missing-positive

/*
Approach-1L Brute force using sorting will give TLE
Time Complexity:    O(N*logN)
Space Complexity:   O(1)
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Find the first missing positive integer
        int missing = 1; // Start checking from 1
        for (int num : nums) {
            if (num == missing) {
                missing++; // If the current number matches, move to the next positive integer
            }
        }
        
        return missing;
    }
};

/*
Approach-2: By marking visited element negative 
Time Complexity:      O(N)
Space Complexity:     O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) // mark the <=0 values as out of bound i.e n+1
            if (num <= 0)
                num = n + 1;

        for (auto& num : nums) {
            int idx = abs(num) - 1;
            if (idx < n)
                nums[idx] = -(abs(nums[idx]));
        }
        for (int i = 0; i < n; i++)
            if (nums[i] >= 0)
                return i + 1;

        return n + 1;
    }
};
