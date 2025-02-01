// problem : https://leetcode.com/problems/special-array-i

/*
Approach : By checking the consecutive element's parity
Time Complexity   :  O(N)
Space Complexity  :  O(1)
*/
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        for(int i=1;i<nums.size();i++)    
            if(nums[i]%2 == nums[i-1]%2)
                return false;
        return true;
    }
};
