// gfg       : https://www.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1
// leetcode  : https://leetcode.com/problems/reverse-words-in-a-string-iii

/*
Approach-1 : Using stack
Time Complexity  :    O(N)
Space Complexity :    O(N)
*/

class Solution {
public:
    string reverseWords(string &s) {
        stack<char> st;
        int i=0;
        string result = "";
      // to remove extra spaces from front
        while(i < s.length() && s[i] == ' ')
            i++;
        while(i < s.length()){
            if(s[i] != ' ')
                st.push(s[i]);
            else{
                while(!st.empty()){
                    result += st.top();
                    st.pop();
                }
                result += ' ';
              // to remove trailing spaces in between words
                while(i + 1 < s.length() && s[i + 1] == ' ')
                    i++;
            }
            i++;
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
      // to remove extra spaces from back
        while (!result.empty() && result.back() == ' ')
            result.pop_back();
        return result;
    }
};
/*
Approach-2 : Using stringstream
Time Complexity  :    O(N)
Space Complexity :    O(N)
*/

class Solution {
public:
    string reverseWords(string &s) {
        stringstream ss(s);
        string result;
        string word;
        while(ss >> word){
            reverse(word.begin(),word.end());
            result += word;
            result += ' ';
        }
        if(!result.empty())
            result.pop_back();
        return result;
    }
};
