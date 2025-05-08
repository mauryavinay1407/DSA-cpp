// problem  : https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1

/*
Approach - Linear scan
Time Complexity     : O(N)
Space Complexity    : O(1)
*/
class Solution {
public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i=0,j=n-1;
        int d = (arr[i + 1] - arr[i]) > (arr[j]-arr[j-1]) ? arr[j] - arr[j-1] : arr[i+1]-arr[i];
        
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1] == d){
                continue;
            }
            else{
                return arr[i] - d;
            }
        }
        return arr[n-1] + d;
    }
};
