// problem : https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

/*
Approach - Using Two Pointer
Time Complexity     :   O(max(m,n)
Space Complexity    :   O(1)
*/
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i][0] == nums2[j][0]) {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                result.push_back({nums1[i][0], nums1[i][1]});
                i++;
            } else {
                result.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while (i < nums1.size()) {
            result.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while (j < nums2.size()) {
            result.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return result;
    }
};
