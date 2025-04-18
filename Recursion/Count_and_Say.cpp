// problem : https://leetcode.com/problems/count-and-say

/*
Approach - Using recursion
Time Complexity      :  O(2^N)
Space Complexity     :  O(N)
*/
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string temp = countAndSay(n - 1);
        string result = "";
        for (int i = 0; i < temp.length(); i++) {
            int count = 1;

            while (i < temp.length() - 1 && temp[i] == temp[i + 1]) {
                count++;
                i++;
            }
            result += to_string(count) + string(1, temp[i]);
        }
        return result;
    }
};
