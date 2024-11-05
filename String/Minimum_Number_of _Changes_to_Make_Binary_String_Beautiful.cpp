//  problem: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful

/*
Approach-1:
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    int minChanges(string s) {
        int count=0;
        int moves=0;
        char ch=s[0];
        for(int i=0;i<s.length();i++){
            if(s[i] == ch)
                count++;
            else{
                if(count%2 == 0)
                    count=1;
                else{
                    moves++;
                    count=0;
                }
                ch=s[i];
            }
        }
        return moves;
    }
};
/* 
Approach-2:  simple 3 line code
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    int minChanges(string s) {
        int moves = 0;
        for(int i=0;i<s.length()-1;i+=2){
            if(s[i] != s[i + 1])
                moves++;
        }
        return moves;
    }
};
