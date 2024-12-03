// problem : https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1

/*
Approach-1: Brute force 
Time Complexity:     O(N^2)
Space Complexity:    O(1)
*/
class Solution {
public:
    int minChar(string str) {
        int n = str.size();
        auto isPalindrome = [&](string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) 
                return false;
            left++;
            right--;
           }
          return true;
        };

        int count = 0;
        // Iterate over the string
        while (!isPalindrome(str)) {
            count++;
            str.pop_back(); // Remove the last character and re-check
        }
        return count;
    }
};

/*
Approach-2: Using LPS(Longest Prefix Suffix)
Time Complexity:     O(N)
Space Complexity:    O(N)
*/
class Solution {
public:
    int minChar(string str){
        string rev=str;
        reverse(rev.begin(),rev.end());
        int size=str.size();
        str+='$' + rev;
        int n=str.size();
        vector<int> lps(n,0);
        int pre=0,suf=1;
        while(suf<str.size()){
            if(str[pre]==str[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else
                pre=lps[pre-1];
            }
        }
        return size-lps[n-1];
    }
};
