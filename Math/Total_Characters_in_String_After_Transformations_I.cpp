// problem  :  https://leetcode.com/problems/total-characters-in-string-after-transformations-i

/*
Approach - By tracking in changes in all letters
Time Complexity      :  O(N + t)
Space Complexity     :  O(1)
*/
class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26, 0);
        for (auto& ch : s) {
            mp[ch - 'a']++;
        }

        for (int count = 1; count <= t; count++) {
            vector<int> temp(26, 0);
            for (int i = 0; i < 26; i++) {
                char ch = i + 'a';
                int freq = mp[i];
                if (ch == 'z') {
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % MOD;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % MOD;
                } else {
                    temp[ch + 1 - 'a'] = (temp[ch + 1 - 'a'] + freq) % MOD;
                }
            }
            mp = temp;
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + mp[i])%MOD;
        }
        return result;
    }
};
