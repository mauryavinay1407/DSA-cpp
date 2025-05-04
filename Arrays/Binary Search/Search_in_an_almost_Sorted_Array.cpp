//  problem  :  https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

/*
Approach - Using binary search
Time Complexity      : O(logN)
Space Complexity     : O(1)
*/
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int i=0,j=arr.size()-1;
        while(i <= j){
            int mid = i + (j - i)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid - 1] == target){
                return mid - 1;
            }
            else if(arr[mid + 1] == target){
                return mid + 1;
            }
            else if(arr[mid] > target){
                j = mid - 2;
            }
            else if(arr[mid] < target){
                i = mid + 2;
            }
        }
        return -1;
    }
};
