// problem : https://leetcode.com/problems/special-array-ii

/*
Approach-1 : Brute force approach
Time Complexity:      O(N^2)
Space Complexity:     O(1)   excluding result vector
*/
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<bool> result;
        for (auto& q : queries) {
            int start = q[0];
            int end = q[1];
            int flag = true;
            for(int i=start; i < end; i++){
                if(nums[i]%2 == nums[i+1]%2){
                    flag = false;
                    break;
                }
            }           
            result.push_back(flag);
        }
        return result;
    }
};
/*
Approach-2 : Using prefix sum
Time Complexity:      O(N + Q)
Space Complexity:     O(N) excluding result vector
*/
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<int> prefix(nums.size(), 0);
        vector<bool> result;
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2)
                prefix[i]++;
        }
        for (auto& q : queries) {
            int start = q[0];
            int end = q[1];
            result.push_back(prefix[start] == prefix[end]);
        }
        return result;
    }
};
/*
Approach-3 : Using 2 pointer
Time Complexity:      O(N + Q)
Space Complexity:     O(N) excluding result vector
*/
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> validRightMostIdx(n, 0);

        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < i) {
                j = i;
            }
            while (j + 1 < n && nums[j] % 2 != nums[j + 1] % 2) {
                j++;
            }
            validRightMostIdx[i] = j;
        }

        vector<bool> result;
        for (auto& query : queries) {
            if (query[1] <= validRightMostIdx[query[0]]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};
