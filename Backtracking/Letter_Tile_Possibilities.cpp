// problem : https://leetcode.com/problems/letter-tile-possibilities

/*
Approach- Using Backtracking
Time Complexity    : O(!n)
Space Complexity   : O(!n*n)
*/

class Solution {
public:
    void find(string tiles, unordered_set<string>& st, string& temp,
              vector<bool>& used) {
        for (int i = 0; i < tiles.length(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            temp += tiles[i];
            st.insert(temp);
            find(tiles, st, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        string temp = "";
        vector<bool> used(tiles.length(), false);
        find(tiles, st, temp, used);
        return st.size();
    }
};
