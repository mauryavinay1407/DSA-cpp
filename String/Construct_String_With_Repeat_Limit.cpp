// problem :  https://leetcode.com/problems/construct-string-with-repeat-limit

/*
Approach: using pointers
Time Complexity    :  O(N)
Space Complexity   :  O(1)
*/
class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        string result = "";
        vector<int> alp(26, 0);
        for (auto& c : s)
            alp[c - 'a']++;
        int i = 25;
        int j = -1;
        while (i >= 0) {
            if (alp[i] > 0) {
                if (j == -1) {
                    int k = (alp[i] < limit) ? alp[i] : limit;
                    alp[i] -= k;
                    while (k-- && result.length() < s.length())
                        result += ('a' + i);
                    if (alp[i] > 0)
                        j = i;
                    i--;
                } else {
                    if (result.length() < s.length())
                        result += ('a' + i);
                    alp[i]--;
                    i = j;
                    j = -1;
                }
            } else
                i--;
        }
        return result;
    }
};
