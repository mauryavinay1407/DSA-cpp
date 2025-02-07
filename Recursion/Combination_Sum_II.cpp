//  leetcode  :  https://leetcode.com/problems/combination-sum-ii
//  gfg       :  https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1

/*
Approach :  Using recursion
Time Complexity     :    O(n * logn + 2^n * target)
Space Complexity    :    O(n)
*/
class Solution {
public:
    void findSum2(vector<int>& candidates, int target, int start,
                  vector<int>& temp, vector<vector<int>>& result) {
        if (target <= 0) {
            if (target == 0)
                result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            findSum2(candidates, target - candidates[i], i + 1, temp, result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findSum2(candidates, target, 0, temp, result);
        return result;
    }
};
