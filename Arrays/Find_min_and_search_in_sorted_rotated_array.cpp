// problem:  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Time: O(logn)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[end])
             start=mid+1;
            else 
             end=mid;
        }
        return nums[start];
    }
};

// problem: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// Time: O(logn)
// Space: O(1)

class Solution {
public:
    int findPivot(vector<int>& nums){
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            while(i<j && nums[i]==nums[i+1])
            i++;
            while(i<j && nums[j]==nums[j-1])
            j--;
            int mid=i+(j-i)/2;
            if(nums[mid]>nums[j])
            i=mid+1;
            else
            j=mid;
        }    
        return i;
    }
    
    int Binary_search(int i,int j,vector<int>& nums,int target){
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
            return mid;
            if(nums[mid]<target)
            i=mid+1;
            else
            j=mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
     int pivot=findPivot(nums);
     
     int val=Binary_search(0,pivot-1,nums,target);
     if(val!=-1)
      return val;
      val=Binary_search(pivot,nums.size()-1,nums,target);

     return val;

    }
};
