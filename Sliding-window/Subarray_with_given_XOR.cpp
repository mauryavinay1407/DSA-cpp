// problem:  https://www.interviewbit.com/problems/subarray-with-given-xor/

/* 
Approach-1: Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
int subarrayXor(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int currXOR = 0;
        for (int j = i; j < nums.size(); j++) {
            currXOR ^= nums[j];
            if (currXOR == k) {
                count++;
              }
            }
        }
    return count;
}

/* 
Approach-2: Optimal using prefix sum
Time Complexity: O(n)
Space Complexity: O(n)
*/

int subarrayXor(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1; 
    int count = 0;
    int currXOR = 0;
    for (int num : nums) {
        currXOR ^= num; 
        if (mp.count(currXOR ^ k)) 
            count += mp[currXOR ^ k];
        mp[currXOR]++;
    }
    return count;
}
