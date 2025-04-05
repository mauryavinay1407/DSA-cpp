// problem : https://leetcode.com/problems/sum-of-all-subset-xor-totals

/*
Approach - 1 :  Using Backtracking
Time Complexity    :  O(2^N)
Space Complexity   :  O(N)
*/
class Solution {
public:
    void find(vector<int>& nums,int i,int XOR,int& sum){
        if(i >= nums.size()){
            return;
        }
        find(nums,i+1,XOR,sum);
        int t = XOR^nums[i];
        sum += t;
        find(nums,i+1,t,sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        find(nums,0,0,sum);
        return sum;
    }
};
/*
Approach - 2 :  Using Bit manipulation
Time Complexity    :  O(N)
Space Complexity   :  O(1)
*/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(auto& num : nums){
            result |= num;
        }
        return result << n - 1 ;
    }
};
