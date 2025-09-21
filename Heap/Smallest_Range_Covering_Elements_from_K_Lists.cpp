// problem:  https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/


/*
Approach-1: using min heap
Time Complexity: O(n*logk)
Space Complexity: O(k)
*/

class Solution {
public:
    using P = pair < int, int >;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue < pair<int, P>, vector<pair<int, P>>,
            greater<pair<int, P>>> pq;
        int minimum, maximum = INT_MIN;
        // insert first element of each row into heap

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maximum = max(maximum, nums[i][0]);
        }
        minimum = pq.top().first;
        vector<int> ans(2);
        ans[0] = minimum;
        ans[1] = maximum;

        pair<int, P> temp;
        int col, row, element;
        while (pq.size() == nums.size()) {
            temp = pq.top();
            pq.pop();

            element = temp.first;
            row = temp.second.first;
            col = temp.second.second;

            if (col + 1 < nums[row].size()) {
                col++;
                pq.push({nums[row][col], {row, col}});
                maximum = max(maximum, nums[row][col]);
                minimum = pq.top().first;

                // If smallest range found
                if (maximum - minimum < ans[1] - ans[0]) {
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            }
        }
        return ans;
    }
};
