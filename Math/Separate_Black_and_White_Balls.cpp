// problem:  https://leetcode.com/problems/separate-black-and-white-balls/description/

/*
Approach: Simply just count the number of 1's before 0 comes and add them into answer because all those 1's have to cross the 0 to seprate black into right side
Time Complexity: O(N)
Space Complexity:O(1)
*/

class Solution {
public:
    long long minimumSteps(string s) {
        long long countOne = 0;
        int i = 0;
        long long count = 0;
        while (i < s.length()) {
            if (s[i] == '1')
                countOne++;
            else {
                count += countOne;
            }
            i++;
        }
        return count;
    }
};

