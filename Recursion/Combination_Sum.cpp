//   leetcode   :  https://leetcode.com/problems/combination-sum/description/
//   gfg        :  https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1

/*
Approach-1 : Using recursion
Time Complexity   :  O(2^n * target)
Space Complexity  :  O(target)
*/
class Solution {
public:
    void findSum(vector<int>& candidates, int target, int start,
                 vector<int>& temp, vector<vector<int>>& result) {
        if (target <= 0) {
            if (target == 0)
                result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            findSum(candidates, target - candidates[i], i, temp, result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        findSum(candidates, target, 0, temp, result);
        return result;
    }
};
/*
Approach-2 : Iterative
Time Complexity   :  O(2^n * target)
Space Complexity  :  O(target)
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        stack<pair<int, int>> s;  // {current index, remaining target}
        
        // Initializing with the first call (start index = 0, target = target)
        s.push({0, target});
        
        while (!s.empty()) {
            auto [start, remaining] = s.top();
            s.pop();
            
            // If the remaining target is 0, we found a valid combination
            if (remaining == 0) {
                result.push_back(temp);
                continue;
            }

            // Start exploring from the current index
            for (int i = start; i < candidates.size(); i++) {
                // If the candidate exceeds the remaining target, we skip it
                if (candidates[i] > remaining) continue;
                
                // Add the current candidate to the temporary vector
                temp.push_back(candidates[i]);
                
                // Push the next state to the stack
                s.push({i, remaining - candidates[i]});
                
                // Pop the last candidate from the temp vector
                temp.pop_back();
            }
        }

        return result;
    }
};
