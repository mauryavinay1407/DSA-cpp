// problem : https://leetcode.com/problems/maximum-score-from-removing-substrings

/*
Approach-1:  Brute-force approach with recursion(TLE)
Time Complexity     :  O(N^2)
Space Complexity    :  O(N)  due to recursion stack
*/
class Solution {
public:
    int calcSum(vector<int>& arr, int i) {
        if (i >= arr.size()) return 0;

        int sum = 0, total = 0;

        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];      
            total += sum;        
        }

        return total + calcSum(arr, i + 1);  
    }

    int subarraySum(vector<int>& arr) {
        return calcSum(arr, 0);
    }
};
/*
Approach-2:  Optimal using Combinatorial technique
Time Complexity     :  O(N)
Space Complexity    :  O(1)  
*/
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += (long long)arr[i] * (i + 1) * (n - i);
        }
        return total;
    }
};
