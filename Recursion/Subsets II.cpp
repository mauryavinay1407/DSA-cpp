//  gfg        :  https://www.geeksforgeeks.org/problems/subset-sum-ii/0
//  leetcode   :  https://leetcode.com/problems/subsets-ii

/*
Approach-1 : Using recursion
Time Complexity    :   O(2^n)
Space Complexity   :   O(n)
*/

class Solution {
public:
    void findSubset(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        findSubset(nums, i + 1, temp, result);
        temp.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        findSubset(nums, i + 1, temp, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        findSubset(nums, 0, temp, result);
        return result;
    }
};
/*
Approach-2 : Iterative
Time Complexity    :   O(2^n)
Space Complexity   :   O(1)
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        int start, end;

        for (int i = 0; i < nums.size(); i++) {
            start = 0;
            end = result.size();
            
            // If it's a duplicate, only consider subsets added in the last step
            if (i > 0 && nums[i] == nums[i - 1])
                start = end / 2;

            for (int j = start; j < end; j++) {
                vector<int> temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
