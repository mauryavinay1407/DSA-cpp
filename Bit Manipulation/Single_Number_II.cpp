// problem:  https://leetcode.com/problems/single-number-ii

/*
Approach: By checking LSB of each number because due to single count of every bit will not be divisible by 3 
Time Complexity:     O(N)
Space Complexity:    O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (auto& num : nums) {
                if ((num >> i) & 1)
                    count++;
            }
            bits[i] = (count % 3 == 0) ? 0 : 1;
        }
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i])
                result += (1 << i);
        }
        return result;
    }
};
