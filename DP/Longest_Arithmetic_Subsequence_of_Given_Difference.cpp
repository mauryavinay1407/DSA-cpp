// problem:  https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description

/*
Approach:1-   Recursion (TLE)
Time Complexity:   O(2^N)
Space Complexity:  O(N)
*/
class Solution {
public:
    int findLongestSubsequence(vector<int>& arr, int diff,int i){
        int result=0;
        for(int j=i+1;j<arr.size();j++){
            if((arr[j]-arr[i]) == diff)
                result=max(result,1 + findLongestSubsequence(arr,diff,j));
        }
        return result;
    }
    int longestSubsequence(vector<int>& arr, int diff) {
        int result=0;
        for(int i=0;i<arr.size();i++){
            result=max(result, 1 + findLongestSubsequence(arr,diff,i));
        }
        return result;
    }
};

/*
Approach:2-   Recursion + Memoization (TLE)
Time Complexity:   O(N^2)
Space Complexity:  O(N)
*/

class Solution {
public:
    int dp[100001];
    int findLongestSubsequence(vector<int>& arr, int diff, int i) {
        if(dp[i] != -1)
            return dp[i];
        int result = 0;
        for (int j = i + 1; j < arr.size(); j++) {
            if ((arr[j] - arr[i]) == diff)
                result = max(result, 1 + findLongestSubsequence(arr, diff, j));
        }
        return dp[i] = result;
    }
    int longestSubsequence(vector<int>& arr, int diff) {
        int result = 0;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < arr.size(); i++) {
            result = max(result, 1 + findLongestSubsequence(arr, diff, i));
        }
        return result;
    }
};

/*
Approach:3-   Using unordered_map
Time Complexity:   O(N)
Space Complexity:  O(N)
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> mp;
        int result = 0;
        for (auto& num : arr) {
                mp[num] = mp[num - diff] + 1;
                result = max(result, mp[num]);
        }
        return result;
    }
};
