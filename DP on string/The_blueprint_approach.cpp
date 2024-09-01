//T.C : O(n^2)
//S.C ; O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        //t[i][j] = true : s[i:j] is a substring where i and j are inclusive indices

        int count = 0;

        for(int L = 1; L <= n; L++) {
            for(int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if(i == j) {
                    t[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1] == true);
                }

                count += t[i][j];
            }
        }

        return count;
    }
};
