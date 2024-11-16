// problem:https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i

/*
Approach-1: Using sliding window 
Time Complexity:    O(N)
Space Complexity:   O(1)
*/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i = 0;
        int j = 1;
        int count = 1;
        vector<int> result(nums.size() - k + 1, -1);
        if (k == 1) {
            for (int i = 0; i < nums.size(); i++) {
                result[i] = nums[i];
            }
            return result;
        }
        while (j < nums.size()) {
            if (nums[j - 1] + 1 == nums[j])
                count++;
            else
                count = 1;
            if (count >= k)
                result[i] = nums[j];
            if (j - i + 1 >= k)
                i++;
            j++;
        }
        return result;
    }
};

/*
Approach-2: Using monotonic deque 
Time Complexity:    O(N)
Space Complexity:   O(N)
*/
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; 
        vector<int> result;

        for(int j = 0; j < n; j++) {

            if(deq.size() == k) {
                deq.pop_front(); 
            }

            if(!deq.empty() && deq.back() != nums[j]-1) { 
                deq.clear();
            }

            deq.push_back(nums[j]);

            if(j >= k-1) {
                if(deq.size() == k) {
                    result.push_back(deq.back()); 
                } else {
                    result.push_back(-1); 
                }
            }
        }

        return result;
    }
};
