// problem:  https://leetcode.com/problems/majority-element/description/

/*
Approach-1 : Brute force using unordered_map
Time : O(N)
Space: O(N)
*/

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> countMap; 
    int n = nums.size();
    
    // Count occurrences of each element
    for (int num : nums) {
        countMap[num]++;
    }
    for (auto& entry : countMap) {
        if (entry.second > n / 2) {
            return entry.first;
        }
    }
    return -1; 
}

/*
Approach-2 : improved space but bad time
Time : O(N^2)
Space: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int maxi = *max_element(nums.begin(), nums.end());
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (maxi == nums[j]) {
                    nums[j] = INT_MIN;
                    count++;
                }
            }
            if (count > nums.size() / 2)
                return maxi;
        }
        return 0;
    }
};

/*
Approach-3: Most Optimal using Boyer Moore voting
Time :O(N)
Space: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_element = NULL;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                major_element = nums[i];
                count++;
            } else if (nums[i] == major_element)
                count++;
            else
                count--;
        }
        return major_element;
    }
};
