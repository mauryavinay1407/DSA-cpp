// problem   :  https://leetcode.com/problems/next-permutation

/*
Approach-1 : Using 2 pointers
Time Complexity     :   O(N) 
Space Complexity    :   O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int point=-1;
     for(int i=nums.size()-1;i>0;i--){
        if(nums[i-1]<nums[i]){
            point=i-1;
            break;
        }
     }

     if(point!=-1){
     int swap_index=-1;
     for(int j=nums.size()-1;j>point;j--){
        if(nums[point]<nums[j]){
         swap_index=j;
         break;
        }
     }
      swap(nums[point],nums[swap_index]);
     }
     reverse(nums.begin()+point+1,nums.end());
     return;
    }
};
/*
Approach-2 : Using 2 pointers advanced
Time Complexity     :   O(N) 
Space Complexity    :   O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int N = A.size(), i = N - 1;
        while (i - 1 >= 0 && A[i - 1] >= A[i]) --i; // find the first element of a descending subarray from the end.
        reverse(begin(A) + i, end(A)); // reverse this descending subarray
        if (i - 1 >= 0) swap(*upper_bound(begin(A) + i, end(A), A[i - 1]), A[i - 1]); // swap A[i-1] with the first element greater than `A[i-1]` in the subarray.
    }
};
