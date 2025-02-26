// problem : https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

/*
Approach-1 : Brute Force
Time Complexity     :    O(N^3)
Space Complexity    :    O(1)
*/


class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        
        for (int k = 1; k <= n; k++) {
            int maxMin = INT_MIN;
    
            for (int i = 0; i <= n - k; i++) {
                int windowMin = INT_MAX;
                
                for (int j = i; j < i + k; j++) {
                    windowMin = min(windowMin, arr[j]);
                }
    
                maxMin = max(maxMin, windowMin);
            }
    
            result.push_back(maxMin);
        }
        
        return result;
    }
};
/*
Approach-2 : Using Monotonic Stack
Time Complexity     :    O(N)
Space Complexity    :    O(N)
*/


class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n), result(n + 1, 0);
        stack<int> s;
    
        // Compute previous smaller elements (left boundary)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
    
        // Clear stack to reuse
        while (!s.empty()) s.pop();
    
        // Compute next smaller elements (right boundary)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
    
        // Find max of mins for each window size
        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1;
            result[windowSize] = max(result[windowSize], arr[i]);
        }
    
        // Fill remaining positions from right to left
        for (int i = n - 1; i >= 1; i--) {
            result[i] = max(result[i], result[i + 1]);
        }
    
        // Remove extra element at index 0
        result.erase(result.begin());
        
        return result;
    }
};
