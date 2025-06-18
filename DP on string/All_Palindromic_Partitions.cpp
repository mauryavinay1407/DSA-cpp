// problem : https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

/*
Approach-1 : Brute force using backtracking
Time Complexity      :     O(2^n * n)
Space Complexity     :     O(2^n * n) for result + O(n) recursion stack
*/
class Solution {
public:
    void findParts(string& s,vector<vector<string>>& result,vector<string>& temp,int i){
        if(i >= s.length()){
            result.push_back(temp);
            return;
        }
        
        for(int j = i; j < s.length(); j++){
            string correct = s.substr(i,j - i + 1);
            string inverted = correct;
            reverse(inverted.begin(),inverted.end());
            
            if(correct == inverted){
                temp.push_back(correct);
                findParts(s,result,temp,j + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> result;
        
        vector<string> temp;
        
        findParts(s,result,temp,0);
        
        return result;
    }
};


/*
Approach-2 : DFS + DP
Time Complexity      :     O(n^2 + 2^n)
Space Complexity     :     O(n^2 + 2^n * n)
*/
class Solution {
public:
    vector<vector<string>> result;
    vector<string> temp;
    vector<vector<bool>> isPal;

    void dfs(string& s, int i) {
        int n = s.length();
        if (i == n) {
            result.push_back(temp);
            return;
        }

        for (int j = i; j < n; ++j) {
            if (isPal[i][j]) {
                temp.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> palinParts(string &s) {
        int n = s.length();
        isPal = vector<vector<bool>>(n, vector<bool>(n, false));

        // DP to mark palindromic substrings
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        dfs(s, 0);
        return result;
    }
};
