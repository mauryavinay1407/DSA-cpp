// problem : https://leetcode.com/problems/shifting-letters-ii

/*
Approach-1 : Brute Force  (TLE)
Time Complexity  :  O(Q*N)      where Q = length of shifts array
Space Complexity :  O(N)
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> letters(n,0);
        for(auto& sh : shifts){
            int start = sh[0];
            int end = sh[1];
            int step = sh[2]==1 ? 1 : -1;
            for(int i = start;i <= end; i++)
                letters[i] += step;
        }
        for(int i=0;i < n; i++){
            int t = ((s[i] - 'a' + letters[i])%26 + 26)%26;
            s[i] = 'a' + t;
        }
        return s;
    }
};

/*
Approach-2 : Optimal using Difference array technique
Time Complexity  :  O(N)      where Q = length of shifts array
Space Complexity :  O(N)
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> letters(n + 1,0);
        for(auto& sh : shifts){
            int start = sh[0];
            int end = sh[1];
            if(sh[2]){
                letters[start]++;
                letters[end + 1]--;
            }
            else{
                letters[start]--;
                letters[end + 1]++;
            }
        }
        for(int i = 1;i <= n; i++)
            letters[i] += letters[i-1];

        for(int i=0;i < n; i++){
            int t = ((s[i] - 'a' + letters[i])%26 + 26)%26;
            s[i] = 'a' + t;
        }
        return s;
    }
};
