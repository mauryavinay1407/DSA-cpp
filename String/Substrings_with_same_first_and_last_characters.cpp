//  problem  : https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1

/*
Approach -  Using combination formula on occurence of each characters
Time Complexity       :  O(N)
Space Complexity      : O(26) ~ O(1)
*/
class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        vector<int> count(26,0);
        int result = 0;
        for(auto& ch : s){
            count[ch - 'a']++;
        }
        for(int i=0;i<26;i++){
            int n = count[i];
            result += (n*(n+1))/2;
        }
        return result;
    }
};
