// problem :
// problem:  https://leetcode.com/problems/string-to-integer-atoi 
// problem:  https://www.geeksforgeeks.org/problems/implement-atoi/1
/*
Approach:
Time Complexity  :    O(N)
Space Complexity :    O(1)
*/
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i] != '\0' && s[i] == ' ')
            i++;
        
        int flag = 1;
        if(s[i] == '+' || s[i] == '-'){
            int x = s[i] == '-';
            flag = 1 - 2*x;
            i++;
        }
        int base = 0;
        while(s[i] >= '0' && s[i] <= '9' && s[i] != '\0'){
            if(base > INT_MAX/10 || (base == INT_MAX/10 && s[i] > '7'))
                return flag == 1 ? INT_MAX : INT_MIN;
            
            base = base*10 + (s[i++] - '0');
        }
        return base*flag;
    }
};
