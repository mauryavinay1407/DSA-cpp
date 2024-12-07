// problem :  https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

/*
Approach:  Using Binary Search (pattern : Minimize the Maximum or Maximize the Minimum)
Time Complexity:    O(N*logN)
Space Complexity:   O(1)
*/
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int result = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
                int ops = 0; 
            for(auto& num : nums){
                ops += (num % mid == 0) ? num/mid - 1 : num/mid ;
            }
            if(ops <= maxOperations){
                result = min(result, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return result;
    }
};
