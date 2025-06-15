// problem  :  https://www.geeksforgeeks.org/problems/smallest-divisor/1

/*
Approach - Using Binary Search
Time Complexity      : O(N*logm)    where N = size of array ,  m = max element in array
Space Complexity     : O(1)
*/
class Solution {
public:
    bool find(vector<int>& arr,int mid,int k){
        int sum = 0;
        for(auto& num : arr){
            sum += num/mid;
            
            if(num%mid){
                sum++;
            }
        }
        return sum <= k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int start = 1;
        int end = *max_element(arr.begin(),arr.end());
        int result;
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(find(arr,mid,k)){
                result = mid;
                end = mid - 1 ;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
};
