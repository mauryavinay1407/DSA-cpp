// problem  :  https://leetcode.com/problems/largest-3-same-digit-number-in-string

/*
Approach - By checking 3 contagious element
Time Complexity        :    O(N)
Space Complexity       :    O(1)
*/
class Solution {
public:
    string largestGoodInteger(string nums) {
        string temp = "";
        string result = "";
        for (int i = 0; i < nums.length() - 2; i++) {
            if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
                temp = nums.substr(i, 3);
                result = max(result, temp);
            }
        }
        return result;
    }
};
