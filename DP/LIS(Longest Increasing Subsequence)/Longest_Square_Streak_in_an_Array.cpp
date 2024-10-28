// problem: https://leetcode.com/problems/longest-square-streak-in-an-array/description/

/*
Approach-1 Recursion + Memoization (TLE)  (same as leetcode-1027)
Time Complexity:    O(N^2)
Space Complexity:   O(N)
*/
class Solution {
public:
    int dp[100001];
    int solve(vector<int>& nums,int j){
        if(dp[j] != -1)
            return dp[j];
        int result=0;
        for(int idx=j+1;idx<nums.size();idx++){
            if((nums[j]-(long long)nums[idx]*nums[idx]) == 0)
                result = max(result,1 + solve(nums,idx));
        }
        return dp[j] = result;
    }
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        memset(dp,-1,sizeof(dp));
        int result=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]-(long long)nums[j]*nums[j]) == 0){
                    result = max(result,2 + solve(nums,j));
                }
            }
        }
        return result ? result : -1 ;
    }
};

/*
Approach-2: Bottom up (TLE)  (same as leetcode-300)
Time Complexity: O(N^2)
Space Complexity: O(N)
*/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int result = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[j] - (long long)nums[i] * nums[i]) == 0) {
                    dp[i] = dp[j] > 0 ? dp[j] + 1 : 2;
                    result = max(result, dp[i]);
                }
            }
        }
        return result ? result : -1;
    }
};

/*
Approach-3: Using sorting and map
Time Complexity: O(N*logN)
Space Complexity: O(N)
*/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<int, int> mp;
        int result = 0;
        for (auto& num : nums) {
            int temp = (long long)num * num;
            if (mp.count(temp)) {
                mp[num] = mp[temp] + 1;
                result = max(result, mp[num]);
            } else
                mp[num]=1;
        }
        return result ? result : -1;
    }
};

/*
Approach-4: Using set
Time Complexity: O(N) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine
(i.e. 2,4,16,256,65536,. and after doing square it will exceed 10^5, so max 5 times
Space Complexity: O(N)
*/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int result = 0;
        for (auto& num : nums) {
            int streak = 0;
            long long curr = num;
            while (st.count(curr)) {
                streak++;
                if (curr * curr > 1e5)
                    break;
                curr *= curr;
            }
            result = max(result, streak);
        }
        return result > 1 ? result : -1;
    }
};
