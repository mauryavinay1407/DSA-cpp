// problem : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

/*
Approach:  Sliding + bit manipulation (very important***)
Time Complexity:     O(N)
Space Complexity:    O(1)
*/
class Solution {
public:
    void updateBits(vector<int>& bits, int num, int val){
        for(int i = 0; i < 32; i++){
            if ((num >> i) & 1)
                bits[i] += val;
        }
    }
    int getTheNumber(vector<int>& bits){
        int num = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i] > 0)
                num |= 1 << i ;
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLength = INT_MAX;
        int i=0;
        int j=0;
        vector<int> bits(32,0);
        while(j<nums.size()){
            updateBits (bits ,nums[j], 1);
            while(i <= j && getTheNumber(bits) >= k){
                minLength = min (minLength, j - i + 1);
                updateBits (bits, nums[i], -1);
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};
