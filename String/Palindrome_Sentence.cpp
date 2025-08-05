// problem  :  https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1

/*
Approach - By checking with ASCII code and using 2 pointers
Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/
class Solution {
public:
    bool isValid(char ch){
        return (isdigit(ch) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
    }    
    bool isPalinSent(string &s) {
        // code here
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(isValid(s[i]) && isValid(s[j])){
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }else{
                    i++;
                    j--;
                }
            }
            else{
                if(isValid(s[i])){
                    j--;
                }else{
                    i++;
                }
            }
        }
        return true;
    }
};
