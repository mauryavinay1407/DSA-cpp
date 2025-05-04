// problem  : https://leetcode.com/problems/number-of-equivalent-domino-pairs


/*
Approach - Using hashmap
Time Complexity     :  O(N*logN)
Space Complexity    :  O(N)
*/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int result = 0;
        for (auto& d : dominoes) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            mp[{d[0], d[1]}]++;
        }
        for (auto& m : mp) {
            int n = m.second;
            result += (n * (n - 1)) / 2;
        }
        return result;
    }
};
