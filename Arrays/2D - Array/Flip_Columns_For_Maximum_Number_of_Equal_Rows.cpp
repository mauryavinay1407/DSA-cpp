// problem:  https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

/*
Approach-1: Brute force(By counting exactly same and exactly inverted rows)
Time Complexity:    O(m*m*n)
Space Complexity:   O(n)
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        for (auto& curr : matrix) {
            vector<int> reversed(n);
            for (int i = 0; i < n; i++)
                reversed[i] = curr[i] == 0 ? 1 : 0;

            int count = 0;
            for (auto& rows : matrix) {
                if (rows == curr || rows == reversed)
                    count++;
            }
            result = max(result, count);
        }
        return result;
    }
};
/*
Approach-2: By using hashmap to store same patterns
Time Complexity:    O(m*n)
Space Complexity:   O(m*n)
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp;
        int result = 0;
        for (auto& row : matrix) {
            string curr = "";
            int first = row[0];
            for (auto& col : row) {
                curr += (first == col) ? "S" : "B";
            }

            mp[curr]++;
        }
        for (auto& m : mp) {
            result = max(result, m.second);
        }
        return result;
    }
};
