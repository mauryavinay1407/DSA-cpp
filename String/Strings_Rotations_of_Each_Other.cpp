// problem: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

/*
Approach-1: Using directly
Time Complexity :      O(m + n) 
Space Complexity:      O(1)
*/
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
    }
};
/*
Approach-2: Using KMP Algorithm
Time Complexity :      O(n)
Space Complexity:      O(n)
*/
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
         if (s1.size() != s2.size()) return false;

    string temp = s1 + s1; 
    int n = temp.size(), m = s2.size();

    // Build LPS array 
    vector<int> lps(m, 0);
    int i = 1, len = 0;

    while (i < m) {
        if (s2[i] == s2[len]) {
            len++;
            lps[i++] = len;
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }

    // Use LPS to search for s2 in temp
    i = 0;
    int j = 0; 

    while (i < n) {
        if (temp[i] == s2[j]) {
            i++;
            j++;
            if (j == m) return true;
        } else {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
    }
};
