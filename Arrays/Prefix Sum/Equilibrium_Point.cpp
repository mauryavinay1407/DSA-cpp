// problem :  https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

/*
Approach: Using prefix sum
Time Complexity  :   O(N)
Space Complexity :   O(1)
*/

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        long long sum = accumulate(arr.begin(),arr.end(),0LL);
        long long leftSum = 0;
    
        for(int i = 0; i < n; i++){
            long long rightSum = sum - leftSum - arr[i];
            if(leftSum == rightSum)
                return i;
            leftSum += arr[i];
        }
        return -1;
    }
};
