// problem  : https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

/*
Approach - Using Backtracking
Time Complexity      :  O(N^k)
Space Complexity     :  O(k)
*/
class Solution {
  public:
    void solve(int idx, int k, string s, string &ans){
        if(k==0 || idx==s.size()){
            if(s>ans) ans = s;
            return;
        }
        for(int i = idx; i<s.length();i++){
            if(s[i]>s[idx]){
                swap(s[i],s[idx]);
                solve(idx+1,k-1,s,ans);
                swap(s[i],s[idx]);
            }
            solve(i+1,k,s,ans);
        }
    }
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans = s;
        solve(0,k,s,ans);
        return ans;
    }
};
