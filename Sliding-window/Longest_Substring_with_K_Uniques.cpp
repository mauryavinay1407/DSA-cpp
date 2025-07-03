// problem  :  https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

/*
Approach - Using sliding window and unordered map to store the frequency of characters
Time Complexity      :  O(N)
Space Complexity     :  O(26) ~ O(1)
*/
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        // code here
        int result = -1;
        unordered_map<char,int> mp;
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            
            if(mp.size() == k){
                result = max(result, i - j + 1);
            }
            
            if(mp.size() > k){
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
