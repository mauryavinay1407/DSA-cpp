// problem : https://leetcode.com/problems/first-completely-painted-row-or-column

/*
Approach-1: brute force using hashmap
Time Complexity    :  O(m*n + s*(m + n)
Space Complexity   :  O(m*n)
*/
class Solution {
public:
    int m, n;
    bool check(int x, int y, vector<vector<int>>& box) {
        // check rows
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!box[x][i]) {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
        // check columns
        for (int i = 0; i < m; i++)
            if (!box[i][y])
                return false;
        return true;
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<vector<int>> box(m, vector<int>(n, 0));
        for (int k = 0; k < arr.size(); k++) {
            auto [i, j] = mp[arr[k]];
            box[i][j] = 1;
            if (check(i, j, box))
                return k;
        }
        return -1;
    }
};
/*
Approach-2: better using hashmap
Time Complexity    :  O(m*n + s)  where s = size of array
Space Complexity   :  O(m*n)
*/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (int k = 0; k < arr.size(); k++) {
            auto [i, j] = mp[arr[k]];
            rows[i]++;
            cols[j]++;
            if (rows[i] == n || cols[j] == m)
                return k;
        }
        return -1;
    }
};
