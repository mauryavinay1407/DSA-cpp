// problem :  https://leetcode.com/problems/construct-k-palindrome-strings

/*
Approach- As we know that each palindrome can have only one odd frequency
Time Complexity   : O(N) 
Space Complexity  : O(1)
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length())
            return false;
        vector<int> counts(26, 0);
        int odds = 0;
        for (auto& l : s) {
            counts[l - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (counts[i] % 2 == 1)
                odds++;
        }
        return odds <= k;
    }
};
