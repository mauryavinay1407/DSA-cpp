// problem : https://leetcode.com/problems/subsets

/*
Approach-1: using Recursive Backtracking
Time Complexity     :  O(N * 2^N)
Space Complexity    :  O(N)
*/
class Solution {
public:
    vector<vector<int>> ans;
    void findSubsets(vector<int>& nums, int i, vector<int>& temp) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        findSubsets(nums, i + 1, temp);
        temp.push_back(nums[i]);
        findSubsets(nums, i + 1, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        findSubsets(nums, 0, temp);
        return ans;
    }
};
/*
Approach-2: Iterative 
Time Complexity     :  O(N * 2^N)
Space Complexity    :  O(N)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};

        for (int num : nums) {
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                vector<int> subset = ans[i];  // Copy existing subset
                subset.push_back(num);        // Add new element
                ans.push_back(subset);        // Store new subset
            }
        }
        return ans;
    }
};
/*
Approach-3: Using bitmasking 
Time Complexity     :  O(N * 2^N)
Space Complexity    :  O(1)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n;  // 2^n subsets
        vector<vector<int>> ans;

        for (int mask = 0; mask < totalSubsets; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {  // Check if bit is set
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
/*
Approach-4: Using DP
Time Complexity     :  O(N * 2^N)
Space Complexity    :  O(1)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> ans(1);
        for (int i = 0; i < A.size(); ++i) {
            int len = ans.size();
            for (int j = 0; j < len; ++j) {
                ans.push_back(ans[j]);
                ans.back().push_back(A[i]);
            }
        }
        return ans;
    }
};
