// problem : https://leetcode.com/problems/minimum-index-of-a-valid-split

/*
Approach-1 : Using Hashmap
Time Complexity     :  O(N)
Space Complexity    :  O(N)
*/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            mp[num]++;
        }
        int x = 0, temp = 0;
        for (auto& m : mp) {
            if (m.second > temp) {
                temp = m.second;
                x = m.first;
            }
        }

        int occurence = count(nums.begin(), nums.end(), x);
        int freq = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == x) {
                freq++;
            }
            if (freq > i + 1 - freq &&
                (occurence - freq) > n - i - 1 - (occurence - freq)) {
                return i;
            }
        }
        return -1;
    }
};

/*
Approach-2 : Using Boyer-Moore(Majority Element)
Time Complexity     :  O(N)
Space Complexity    :  O(1)
*/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int freq = 0;
        int x = 0;
        for(auto& num : nums){
            if(freq == 0){
                x = num;
            }
            freq += (x == num) ? 1 : -1;
        }
        int occurence = count(nums.begin(),nums.end(),x);

        int countX = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == x){
                countX++;
            }
            if(2*countX > i + 1 && 2 * (occurence - countX) > (n - i - 1)){
                return i;
            }
        }
        return -1;
    }
};
