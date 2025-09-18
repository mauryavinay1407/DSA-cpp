// problem  :  https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

/*
Approach-1: Brute Force
Time Complexity       :  O(N^3) (TLE) 
Space Complexity      :  O(1)
*/
class Solution {
public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int result = 0;
        for(int start = 0 ; start < arr.size(); start++){
            for(int end = start; end < arr.size(); end++){
                int mini = *min_element(arr.begin() + start, arr.begin() + end + 1);
                result += mini;
            }
        }
        return result;
    }
};
/*
Approach-2: Using the concept that a number will be involved in x * (m + 1) * (n + 1) subarray where m = no of elements <= x in left and n = no of elements <= x in right
Time Complexity       :  O(N)
Space Complexity      :  O(N)
*/
class Solution {
public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> leftSt;
        stack<int> rightSt;

        // Calculate left[i]: distance to previous smaller element
        for (int i = 0; i < n; i++) {
            while (!leftSt.empty() && arr[i] < arr[leftSt.top()]) {
                leftSt.pop();
            }
            if (!leftSt.empty()) {
                left[i] = i - leftSt.top() - 1;
            } else {
                left[i] = i;
            }
            leftSt.push(i);
        }

        // Calculate right[i]: distance to next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!rightSt.empty() && arr[i] <= arr[rightSt.top()]) {
                rightSt.pop();
            }
            if (!rightSt.empty()) {
                right[i] = rightSt.top() - i - 1;
            } else {
                right[i] = n - i - 1;
            }
            rightSt.push(i);
        }

        // Compute final result
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += arr[i] * (left[i] + 1) * (right[i] + 1);
        }

        return result;
    }
};
