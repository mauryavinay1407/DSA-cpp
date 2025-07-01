// problem  :  http://geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1

/*
Approach - Using sliding window and unordered map to store the frequency of characters
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/
class Solution {
public:
    int substrCount(string &s, int k) {
        unordered_map<char,int> mp;
        
        int j = 0;
        int result = 0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            if(i - j + 1 == k){
                if(mp.size() == k - 1){
                    result++;
                }
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    mp.erase(s[j]);
                }
                j++;
            }
        }
        return result;
    }
};
