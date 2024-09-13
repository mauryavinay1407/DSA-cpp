// problem:  https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

/*
Approach:1
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
     while(a || b || c){
        if(c & 1){
          if(!(a & 1) && !(b & 1))
           flips++;
        }
        else{
            if(a & 1)
            flips++;
            if(b & 1)
            flips++;
        }
        a>>=1;
        b>>=1;
        c>>=1;
     }
     return flips;
    }
};
