// problem :  https://leetcode.com/problems/longest-substring-without-repeating-characters/description

/*
Approach: Using sliding window
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<bool> count(256,0);
      int longestSub=0;
      int left=0,right=0;
      while(right<s.length()){
      // to remove seen elements   
        while(count[s[right]])
          count[s[left++]]=false;
      // for unique elements  
        count[s[right]]=true;
      // store the length
       longestSub=max(longestSub,right-left+1);
       right++; 
      }
      return longestSub;
    }
};
