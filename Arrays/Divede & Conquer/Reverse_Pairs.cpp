// problem: https://leetcode.com/problems/reverse-pairs/description/

/*
Approach-1: Brute Force 
Time Complexity: O(N^2)
Space Complexity: O(1)
*/
class Solution {
public:
int reversePairs(vector<int>&a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) count++;
        }
    }
    return count;
}
};
/*
Approach-2: Optimal solution using merge sort 
Time Complexity: O(N*logN)
Space Complexity: O(N)
*/
class Solution {
public:
    void merge(vector<int>& a, int low, int mid, int high) {
        int first = low;
        int second = mid + 1;
        vector<int> temp;
        int count = 0;
        while (first <= mid && second <= high) {
            if (a[first] <= a[second])
                temp.push_back(a[first++]);
            else
                temp.push_back(a[second++]);
        }
        while (first <= mid)
            temp.push_back(a[first++]);

        while (second <= high)
            temp.push_back(a[second++]);

        for (int i = low; i <= high; i++)
            a[i] = temp[i - low];
    }

    int countPairs(vector<int>& a, int low, int mid, int high) {
        int start = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++) {
            while (start <= high && a[i] > 2L * a[start])
                start++;
            count += (start - (mid + 1));
        }
        return count;
    }

    int mergeSort(vector<int>& a, int low, int high) {
        if (low < high) {
            int count = 0;
            int mid = low + (high - low) / 2;
            count += mergeSort(a, low, mid);
            count += mergeSort(a, mid + 1, high);
            count += countPairs(a, low, mid, high);
            merge(a, low, mid, high);
            return count;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};
