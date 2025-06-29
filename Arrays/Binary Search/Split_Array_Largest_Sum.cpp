// GFG         : https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
// Leetcode    : https://leetcode.com/problems/split-array-largest-sum

/*
Approach -  Using Binary Search
Time Complexity      :  O(N*logS)     where S = sum of all elements in the array
Space Complexity     :  O(1)
*/
class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        // code here
        long long left = *max_element(arr.begin(),arr.end());
        long long right = accumulate(arr.begin(),arr.end(),0LL);
        
        int result = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            
            int countArr = 1;
            int sum = 0;
            for(int i=0;i<arr.size();i++){
                sum += arr[i];
                if(sum <= mid){
                    continue;
                }else{
                    countArr++;
                    sum = arr[i];
                }
            }
            if(countArr <= k){
                result = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return result;
    }
};
