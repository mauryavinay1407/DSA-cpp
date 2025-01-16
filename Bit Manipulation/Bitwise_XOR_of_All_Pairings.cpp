// problem : https://leetcode.com/problems/bitwise-xor-of-all-pairings

/*
Approach: Using XOR property
Time Complexity    :  O(N)
Space Complexity   :  O(1)
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int XOR = 0;
        if(m % 2 != 0) { 
            for(int &num : nums2) {
                XOR ^= num;
            }
        }
        if(n % 2 != 0) { 
            for(int &num : nums1) {
                XOR ^= num;
            }
        }
        return XOR;
    }
};
