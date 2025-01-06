// problem : https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1

/*
Approach- Using sorting andt two pointers
Time Complexity    : O(N*logN)   
Space Complexity   : O(1)
*/

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if(arr.size() < 2)
            return {};
        vector<int> result(2);
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        int absD = INT_MAX;
        while(i < j){
            int sum = arr[i] + arr[j];
            if(abs(sum - target) < absD){
                result[0] = arr[i];
                result[1] = arr[j];
                absD = abs(sum - target);
            }
            if(sum == target){
                break;
            }
            else if(sum > target)
                j--;
            else
                i++;
        }
        return result;
    }
};
