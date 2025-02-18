// gfg       : https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1
// leetcode  : https://leetcode.com/problems/k-closest-points-to-origin

/*
Approach- Using max heap
Time Complexity    :  O(N*logK) 
Space Complexity   :  O(k) 
*/

class Solution {
public:
    int findArea(int l, int b) { return l * l + b * b; }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for (auto& point : points) {
            int area = findArea(point[0], point[1]);
            maxHeap.push({area, point});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
