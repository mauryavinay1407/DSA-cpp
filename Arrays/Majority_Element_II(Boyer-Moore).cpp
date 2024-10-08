// problem: https://leetcode.com/problems/majority-element-ii/description/

/*
Approach-1: Brute force using unordered_map
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;  
        int n = nums.size();
        vector<int> result;
        // Count occurrences of each element
        for (int num : nums) {
            countMap[num]++;
        }
        // Find all elements that occur more than n / 3 times
        for (auto& entry : countMap) {
            if (entry.second > n / 3) {
                result.push_back(entry.first);
            }
        }
        return result;
    }
};
/*
Approach-2: Most optimal using Boyer Moore voting
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major_element1 = NULL;
        int major_element2 = NULL;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == major_element1)
                count1++;
            else if (nums[i] == major_element2)
                count2++;
            else if (count1 == 0) {
                major_element1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                major_element2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        // verification
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == major_element1)
                count1++;
            else if (nums[i] == major_element2)
                count2++;
        }
        if (count1 > n / 3 && count2 > n / 3)
            return {major_element1, major_element2};
        else if (count1 > n / 3)
            return {major_element1};
        else if (count2 > n / 3)
            return {major_element2};

        return {};
    }
};
