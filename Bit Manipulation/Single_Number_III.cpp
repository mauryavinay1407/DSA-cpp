// problem:  https://leetcode.com/problems/single-number-iii

/*
Approach: By checking first odd occurence of set bits from LSB
Time Complexity:     O(N)
Space Complexity:    O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int count=0;
        int x;
        for(int i=0;i<32;i++){
            int count=0;
            for(auto& num: nums){
                if((num >> i) & 1)
                    count++;
            }
            if(count%2 != 0){
                x = i;
                break;
            }
        }
        int XOR_1 = 0;
        int XOR_2 = 0;
        for(auto& num: nums){
            if((num >> x) & 1)
                XOR_1^= num;
            else
                XOR_2^= num;
        }
        return {XOR_1,XOR_2};
    }
};
