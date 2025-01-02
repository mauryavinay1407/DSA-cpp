// problem : https://leetcode.com/problems/count-vowel-strings-in-ranges

/*
Approach-1:  Brute force
Time Complexity  :  O(Q * N)  
Space Complexity :  O(1)
*/
class Solution {
public:
    bool isVowel(char c) {
        // Check if the character is a vowel
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result; // To store the results for each query

        // Process each query one by one
        for (auto& q : queries) {
            int start = q[0];
            int end = q[1];
            int count = 0; // To count the valid words for the current query

            // Iterate through the range [start, end]
            for (int i = start; i <= end; i++) {
                string word = words[i];
                if (isVowel(word[0]) && isVowel(word[word.length() - 1])) {
                    count++; // Increment count if the word starts and ends with a vowel
                }
            }

            result.push_back(count); // Store the result for the current query
        }

        return result; // Return the results for all queries
    }
};

/*
Approach-2:  Using prefix sum
Time Complexity  :  O(Q + N)  
Space Complexity :  O(N)
*/

class Solution {
public:
    bool isVowel(string str) {
      // check whether first and last chars are vowels
        int m = str.length();
        bool start = str[0] == 'a' || str[0] == 'e' || str[0] == 'i' ||
                     str[0] == 'o' || str[0] == 'u';
        bool end = str[m - 1] == 'a' || str[m - 1] == 'e' ||
                   str[m - 1] == 'i' || str[m - 1] == 'o' || str[m - 1] == 'u';
        return start && end;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n, 0);
      
      // calculating prefix sum
        for (int i = 0; i < n; i++) {
            if (isVowel(words[i])) {
                if (i == 0)
                    prefix[0] = 1;
                else {
                    prefix[i] = prefix[i - 1] + 1;
                }
            } else
                prefix[i] = i == 0 ? 0 : prefix[i - 1];
        }
      
        vector<int> result;
      // processing all queries
        for (auto& q : queries) {
            int start = q[0];
            int end = q[1];
            if (start == 0)
                result.push_back(prefix[end]);
            else
                result.push_back(prefix[end] - prefix[start - 1]);
        }
        return result;
    }
};
