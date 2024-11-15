// problem:  https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted

/*
Approach: find non-decreasing sequence from front and back and merge them 
Time Complexity:     O(N)
Space Complexity:    O(1)
*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int front = 0;
        while (front < n - 1 && arr[front] <= arr[front + 1])
            front++;
        if (front == n - 1)
            return 0;
        int back = n - 1;
        while (back > 0 && arr[back] >= arr[back - 1])
            back--;

        int minLength = min(n - front - 1, back);
        int i = 0, j = back;
        while (i <= front && j < n) {
            if (arr[i] <= arr[j]) {
                minLength = min(minLength, j - i - 1);
                i++;
            } else
                j++;
        }
        return minLength;
    }
};
