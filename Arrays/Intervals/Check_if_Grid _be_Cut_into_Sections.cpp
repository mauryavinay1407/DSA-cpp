// problem : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections

/*
Approach - Using sorting 
Time Complexity       : O(N*logN)
Space Complexity      : O(N)
*/

class Solution {
public:
    using P = pair<int, int>;
    bool static customComparator(const P& a, const P& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<P> x_axis;
        vector<P> y_axis;
        for (auto& rect : rectangles) {
            x_axis.push_back({rect[0], rect[2]});
            y_axis.push_back({rect[1], rect[3]});
        }
        sort(begin(x_axis), end(x_axis), customComparator);
        sort(begin(y_axis), end(y_axis), customComparator);
        int count = 0;
        int start = 0, end = 0;
        for (auto& x : x_axis) {
            if (x.first >= end) {
                count++;
                start = x.first;
                end = x.second;
            } else {
                start = min(start, x.first);
                end = max(end, x.second);
            }
            if (count == 3) {
                return true;
            }
        }
        count = 0;
        start = 0, end = 0;
        for (auto& y : y_axis) {
            if (y.first >= end) {
                count++;
                start = y.first;
                end = y.second;
            } else {
                start = min(start, y.first);
                end = max(end, y.second);
            }
            if (count == 3) {
                return true;
            }
        }
        return false;
    }
};
