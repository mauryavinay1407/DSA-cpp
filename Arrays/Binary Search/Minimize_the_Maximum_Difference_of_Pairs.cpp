// problem : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs

/*
Approach - Using Binary search + Greedy
Time Complexity        :    O(N*LogN + N*LogD)
Space Complexity       :    O(1)
*/
class Solution {
public:
    bool canPossible(vector<int>& nums, int p, int mid) {
        int i = 0;
        int pairs = 0;

        while (i < nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                pairs++;
                i += 2;
            } else {
                i++;
            }
        }

        return pairs >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums[n - 1] - nums[0];

        int result = INT_MAX;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (canPossible(nums, p, mid)) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};
