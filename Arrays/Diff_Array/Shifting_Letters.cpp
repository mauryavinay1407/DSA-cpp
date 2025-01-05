// problem : https://leetcode.com/problems/shifting-letters

/*
Approach-1 : Brute Force (TLE)
Time Complexity   :  O(N*N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<long> letters(n, 0);
        for (int i = 0; i < n; i++) {
            for(int j=0;j<=i;j++){
                letters[j] += shifts[i];
            }            
        }
        for (int i = 0; i < n; i++) {
            int t = ((s[i] - 'a' + letters[i]) % 26 + 26) % 26;
            s[i] = 'a' + t;
        }
        return s;
    }
};

/*
Approach-2 : Optimal Using Difference array technique
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<long> letters(n + 1, 0);
        for (int i = 0; i < n; i++) {
            letters[0] += shifts[i];
            letters[i + 1] -= shifts[i];
        }
        for (int i = 1; i <= n; i++)
            letters[i] += letters[i - 1];

        for (int i = 0; i < n; i++) {
            int t = ((s[i] - 'a' + letters[i]) % 26 + 26) % 26;
            s[i] = 'a' + t;
        }
        return s;
    }
};
