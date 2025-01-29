//  problem :  https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

/*
Approach-1 : using recursion
Time Complexity: O(N!)
Space Complexity: O(N × N!) (excluding output storage, it is O(N) for recursion + frequency array).
*/
// Duplicates are also allowed i.e. i/p - KK o/p - KK KK
class Solution {
  public:
    void find(string& s, string& ds, vector<string>& ans, vector<int>& freq) {
        if (ds.size() == s.size()) {
            ans.push_back(ds);
            return;
        }
        for (int idx = 0; idx < s.size(); idx++) {
            if (!freq[idx]) {
                ds.push_back(s[idx]);
                freq[idx] = 1;
                find(s, ds, ans, freq);
                freq[idx] = 0;
                ds.pop_back();
            }
        }
    }


    vector<string> findPermutation(string &s) {
        vector<string> ans;
        string ds;
        vector<int> freq(s.size(), 0);
        find(s, ds, ans, freq);
        return ans;
    }
};
/*
Approach-2 : using recursion & backtracking 
Time Complexity: O(N!)
Space Complexity: O(N × N!) 
*/
// Unique are also allowed i.e. i/p - KK o/p - KK
class Solution {
  public:
    void find(string& s, int i,unordered_set<string>& ans){
        if(i == s.length()){
            ans.insert(s);
            return;
        }
        for(int idx = i; idx < s.length(); idx++){
            swap(s[i],s[idx]);
            find(s,i + 1,ans);
            swap(s[i],s[idx]);
        }
    }
    vector<string> findPermutation(string &s) {
        unordered_set<string> ans;
        find(s,0,ans);
        vector<string> result(ans.begin(),ans.end());
        return result;
    }
};
