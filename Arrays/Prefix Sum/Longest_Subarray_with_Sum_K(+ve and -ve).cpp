// problem : https://geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

/*
Approach-1: Brute force using 3 loops
Time Complexity   :  O(N^3)
Space Complexity  :  O(1)
*/
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(); 
        int result = 0;
        for (int i = 0; i < n; i++) { // starting index
            for (int j = i; j < n; j++) { // ending index
                // add all the elements of
                // subarray = a[i...j]:
                int sum = 0;
                for (int K = i; K <= j; K++) {
                    sum += arr[K];
                }
    
                if (sum == k)
                    result = max(result, j - i + 1);
            }
        }
        return result; 
    }
};
/*
Approach-2: Better using 2 loops
Time Complexity   :  O(N^2)
Space Complexity  :  O(1)
*/
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int result = 0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                if(sum == k)
                    result = max(result,j - i + 1);
            }
        }
        return result;
    }
};
/*
Approach-3: Optimal using prefix sum and hashmap
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int i=0;
        int prefixSum=0;
        int result = 0;
        mp[0] = -1;
        while(i < n){
            prefixSum += arr[i];
            
            // check whether sum - k is present in map or not
            if(mp.count(prefixSum - k)){
                result = max(result,i - mp[prefixSum - k]);
            }
            
            // check sum is present , if not present the include
            if(!mp.count(prefixSum)){
                mp[prefixSum] = i;
            }
            i++;
        }
        return result;
    }
};
