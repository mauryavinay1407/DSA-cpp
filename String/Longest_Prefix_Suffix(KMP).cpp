// problem  :   https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1


/*
Approach - Using KMP Algorithm
Time Complexity       :  O(N)
Space Complexity      :  O(N)
*/
class Solution {
public:
    int getLPSLength(string &s) {
        // code here
        vector<int> lps(s.length(),0);
        int pre = 0,suf = 1;
        while(suf < s.length()){
            if(s[pre] == s[suf]){
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            else{
                if(pre == 0){
                    lps[suf] = 0;
                    suf++;
                }else{
                    pre = lps[pre - 1];
                }
            }
        }
        return lps[s.length() - 1];
    }
};
