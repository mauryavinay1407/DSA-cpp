// problem : https://leetcode.com/problems/remove-all-occurrences-of-a-substring

/*
Approach - 1:  Brute force
Time Complexity    :  O(m*n)
Space Complexity   :  O(1)
*/
class Solution {
public:
    string removeOccurrences(string str, string part) {

        int pos = str.find(part);

        while (pos != string::npos) {
            str.erase(pos, part.length());
            pos = str.find(part);
        }

        return str;
    }
};
/*
Approach - 2:  Using string as a stack
Time Complexity    :  O(m*n)
Space Complexity   :  O(1) // not including space of result
*/
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int i = 0;
        while (i < s.length()) {
            result += s[i];
            if (result.length() >= part.length() &&
                result.substr(result.length() - part.length(), part.length()) ==
                    part) {
                result.erase(result.length() - part.length());
            }
            i++;
        }
        return result;
    }
};
