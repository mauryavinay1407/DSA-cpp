// problem: https://leetcode.com/problems/rotate-string

/*
Approach-1: Brute force using rotate
Time Complexity:    O(N^2)
Space Complexity:   O(1)
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();
        if (m != n) 
            return false;
        for (int rotationCount = 1; rotationCount <= m; ++rotationCount) {
            rotate(s.begin(), s.begin() + 1, s.end()); //it says that I want (s.begin()+1)th character to become the first character now. i.e. shifting left by one
            if (s == goal) 
                return true;
        }
        return false;
    }
};

/*
Approach-2: By concatenating string with itself bcuz it contains all possible rotation of a string
Time Complexity:    O(N)
Space Complexity:   O(N)
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        s += s;
        return s.find(goal) != string::npos ;
    }
};
