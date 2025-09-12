// problem :  https://leetcode.com/problems/vowels-game-in-a-string


/*
Approach-1   Simple math
Time Complexity :  O(n) 
Space Complexity:  O(1) 
*/
class Solution {
public:
    bool doesAliceWin(string s) {

        for(char &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }

        return false;
    }
};


/*
Approach-2 Using one liner STL
Time Complexity  : O(n)
Space Complexity : O(1)
*/
class Solution {
public:
    bool doesAliceWin(string s) {
        auto lambda = [](char ch) {
            return string("aeiou").find(ch) != string::npos;
        };

        return any_of(s.begin(), s.end(), lambda);
    }
};
