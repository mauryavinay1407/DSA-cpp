// problem : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence

/*
Approach - Using backtracking
Time Complexity    :  O(!N)
Space Complexity   :  O(N)
*/

class Solution {
public:
    bool dfs(int n, vector<bool>& used, vector<int>& result, int i) {
        if (i == result.size())
            return true;
        if (result[i])
            return dfs(n, used, result, i + 1);
        for (int num = n; num >= 1; num--) {
            if (used[num])
                continue;
            if (num != 1 && (i + num >= result.size() || result[i + num]))
                continue;
            result[i] = num;
            if (num != 1)
                result[i + num] = num;
            used[num] = true;
            if (dfs(n, used, result, i + 1))
                return true;
            used[num] = false;
            result[i] = 0;
            if (num != 1)
                result[i + num] = 0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        if (n == 1)
            return {1};
        vector<bool> used(n + 1, false);
        vector<int> result(2 * n - 1, 0);
        dfs(n, used, result, 0);
        return result;
    }
};
