// problem:  https://leetcode.com/problems/maximum-xor-for-each-query

/*
Approach- By calculation the cumulative XOR and doing XOR with k
Time Complexity:    O(N)
Space Complexity:   O(N)
*/
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = (1 << maximumBit) - 1;
        int n = nums.size();
        vector<int> XORs;
        vector<int> result(n);
        int x = 0;
        for (int& num : nums) {
            x ^= num;
            XORs.push_back(x);
        }
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = XORs[j++] ^ k;
        }
        return result;
    }
};

/*
Approach- by directly calculating XOR and storing them without taking extra vector to store XORs
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = (1 << maximumBit) - 1;
        int n = nums.size();
        vector<int> result(n);
        int XOR = 0;
        for (int i = 0; i < n; i++) {
            XOR ^= nums[i];
            result[n - i - 1] = XOR ^ k;
        }
        return result;
    }
};
