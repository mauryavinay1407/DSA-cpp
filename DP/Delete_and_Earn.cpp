// problem:  https://leetcode.com/problems/delete-and-earn/description/

/*
Approach-1: Recursion + Memoization
Time Complexity: O(n + klogk)
Space Complexity: o(k)     
where k: no of distinct number
*/

class Solution {
public:
     int dp[20000];
     int findMax(int i, vector<int>& nums, unordered_map<int, int>& mp) {
        if (i < 0)                            
            return 0;
        if (i == 0)
            return nums[i] * mp[nums[i]];
        if(dp[i]!=-1)
        return dp[i];

        int take = nums[i] * mp[nums[i]];
        
        if(nums[i - 1] == nums[i] - 1)
            take+= findMax(i - 2, nums, mp);
        else
            take+= findMax(i - 1, nums, mp);
            
        int skip = findMax(i - 1, nums, mp);
        return dp[i]= max(take, skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        memset(dp,-1,sizeof(dp));
        for (auto& num : nums)
            mp[num]++;
        nums.clear();
        for (auto& m : mp)
            nums.push_back(m.first);
        sort(nums.begin(), nums.end());
 
        int n = nums.size();
        return findMax(n - 1, nums, mp);
    }
};


/*
Approach-2: Bottom-up
Time Complexity: O(n + k)
Space Complexity: o(n)     
where k: no of distinct number
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(20001);
        vector<int> dp(20001,0);

        for(auto& num:nums) freq[num]++;

        dp[1]=freq[1];
        for(int i=2;i<=maxi;i++)
        dp[i]=max(dp[i-1],dp[i-2]+freq[i]*i);

        return dp[maxi];
    }
};
