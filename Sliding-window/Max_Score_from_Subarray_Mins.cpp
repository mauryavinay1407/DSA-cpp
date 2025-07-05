// problem : https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

/*
Approach - Using simple simulation and finding max
Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/
class Solution {
public:
    int maxSum(vector<int> &arr) {
        // code here
        int result = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            result = max(result,arr[i] + arr[i + 1]);
        }
        return result;
    }
};
