// problem:  https://leetcode.com/problems/maximum-width-ramp/description

/*
Approach-1: using two loops(TLE)
Time Complexity: O(N^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidth = 0;
       for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<=nums[j])
            maxWidth=max(maxWidth,j-i);
        }
       }
        return maxWidth;
    }
};

/*
Approach-2: Using Two pointer
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidth = 0;
        int n = nums.size();
        vector<int> maxToRight(n, 0);
        maxToRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxToRight[i] = max(maxToRight[i + 1], nums[i]);
        }
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (j < n && nums[i] <= maxToRight[j]) {
                maxWidth = max(maxWidth, j - i);
                j++;
            }
            i++;
        }
        return maxWidth;
    }
};
