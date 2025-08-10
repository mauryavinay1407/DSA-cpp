// problem: https://leetcode.com/problems/reordered-power-of-2

/*
Approach - Using
Time Complexity     :  O(d*logd) where d = no of digit in number
Space Complexity    :  O(1) 
*/
class Solution {
public:
    bool check(string& nums) {
        string temp = "";
        int t = 0;
        while (nums.length() >= temp.length() && t < 31) {
            temp += to_string(1 << t);
            sort(temp.begin(), temp.end());
            if (temp == nums) {
                return true;
            }
            temp = "";
            t++;
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        string nums = to_string(n);
        sort(nums.begin(), nums.end());
        return check(nums);
    }
};
