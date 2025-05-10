// problem  :  https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

/*
Approach - Using Prefix Sum and hashmap
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> mp;
        int result = 0;
        int prefixSum = 0;
        for(int i=0;i<arr.size();i++){
            prefixSum += (arr[i] > k) ? 1 : -1;
            
            if(prefixSum > 0){
                result = i + 1;
            }
            
            else{
                if(mp.count(prefixSum - 1)){
                    result = max(result,i - mp[prefixSum - 1]);
                }
            }
            
            if(!mp.count(prefixSum)){
                mp[prefixSum] = i;
            }
        }
        return result;
    }
};
