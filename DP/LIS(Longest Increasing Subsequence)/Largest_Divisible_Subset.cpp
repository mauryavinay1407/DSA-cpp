// problem : https://www.geeksforgeeks.org/problems/largest-divisible-subset--170643/1

/*
Approach-1 : Using recursion (TLE)
Time Complexity     :  O(N*2^N)
Space Complexity    :  O(N)
*/
class Solution {
public:
    void findSubset(vector<int>& arr, int i, int prev, vector<int>& temp, vector<int>& result) {
        if (i >= arr.size()) {
            if (result.size() < temp.size()) {
                result = temp;
            } else if (result.size() == temp.size()) {
                if (result < temp) {
                    result = temp;
                }
            }
            return;
        }

        if (temp.empty() || arr[i] % prev == 0) {
            temp.push_back(arr[i]);
            findSubset(arr, i + 1, arr[i], temp, result);
            temp.pop_back();
        }

        findSubset(arr, i + 1, prev, temp, result);
    }

    vector<int> largestSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<int> result, temp;
        findSubset(arr, 0, 1, temp, result);
        return result;
    }
};
/*
Approach-2 : Using same as LIS pattern
Time Complexity     :  O(N*2)
Space Complexity    :  O(N)
*/
class Solution {
public:

    vector<int> largestSubset(vector<int>& arr) {
        int n  = arr.size();
        sort(arr.rbegin(), arr.rend());
    
        vector<int> dp(n, 1);
    
        vector<int> prev_idx(n, -1);
    
        int maxL = 1;
        int last_idx = 0;
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev_idx[i] = j;
                }
            }
    
            if (dp[i] > maxL) {
                maxL = dp[i];
                last_idx = i;
            }
        }

        vector<int> result;
        while(last_idx != -1){
            result.push_back(arr[last_idx]);
            last_idx = prev_idx[last_idx];
        }
        return result;
    }
};
