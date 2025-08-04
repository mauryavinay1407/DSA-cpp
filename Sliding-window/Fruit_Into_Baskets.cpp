// problem https://leetcode.com/problems/fruit-into-baskets

/*
Approach - Using 2 pointer + sliding window + hashmap
Time Complexity     :  O(N)
Space Complexity    :  O(1)
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        int j = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < fruits.size(); i++) {
            mp[fruits[i]]++;
            while (mp.size() > 2) {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0) {
                    mp.erase(fruits[j]);
                }
                j++;
            }
            result = max(result, i - j + 1);
        }
        return result;
    }
};
