// problem : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

/*
Approach-1: (Super Brute Force)
Time Complexity  : O(n^2)
Space Complexity : O(n)
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted(n);

        for(int r = 0; r < n; r++) {

            int idx = 0;
            for(int i = r; i < n; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            for(int i = 0; i < r; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            //check if sorted;
            bool isSorted = true;
            for(int i = 0; i < n-1; i++) {
                if(sorted[i] > sorted[i+1]) {
                    isSorted = false;
                    break;
                }
            }

            if(isSorted) {
                return true;
            }

        }

        return false;
    }
};

/*
Approach-2: (Better Brute Force)
Time Complexity  : O(n^2)
Space Complexity : O(n)
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        for(int r = 0; r < n; r++) {
            bool isSorted = true;
            for(int i = 0; i < n; i++) {
                if(sorted[i] != nums[(i + r)%n]) {
                    isSorted = false;
                    break;
                }
            }

            if(isSorted) {
                return true;
            }

        }

        return false;
    }
};
/*
Approach-3:  Optimal noob
Time Complexity  : O(n)
Space Complexity : O(1)
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int idx = -1;
        int pre = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                idx = i;
                pre = i - 1;
                break;
            }
        }
        if (idx == -1)
            return true;
        while (idx < nums.size() - 1) {
            if (nums[idx] > nums[idx + 1])
                return false;
            idx++;
        }
        int j = 0;
        while(j <= pre){
            if(nums[idx] > nums[j])
                return false;
            j++;
        }
        return true;
    }
};
/*
Approach-4:  Optimal pro
Time Complexity  : O(n)
Space Complexity : O(1)
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i + 1)% n])
                peak++;
        }
        return peak <= 1;
    }
};
