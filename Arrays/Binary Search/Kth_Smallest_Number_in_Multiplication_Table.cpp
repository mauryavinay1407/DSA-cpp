// problem  :  https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

/*
Brute force can be done forming table first then use heap
Approach - using binary search
Time Complexity      : O(m*log(m*n))
Space Complexity     : O(1)
*/
class Solution {
public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int low = 1;
        int high = m*n;
        int result = m*n;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0;
            
            for(int i = 1; i <= m; i++){
                count += min(mid/i,n);
            }
            if(count >= k){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }
};
