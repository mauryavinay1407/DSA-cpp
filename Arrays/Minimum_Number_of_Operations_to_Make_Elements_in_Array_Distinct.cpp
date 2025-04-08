// problem : https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct

/*
Approach - Solve from end
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        int i = nums.size() - 1;
        for (; i >= 0; i--) {
            if (st.count(nums[i])) {
                break;
            } else {
                st.insert(nums[i]);
            }
        }
        if (i < 0) {
            return 0;
        }
        int rem = nums.size() - st.size();
        return (rem + 3 - 1) / 3;
    }
};
