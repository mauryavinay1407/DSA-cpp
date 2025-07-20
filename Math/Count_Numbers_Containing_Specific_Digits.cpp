// problem : https://www.geeksforgeeks.org/problems/count-numbers-containing-specific-digits/1

/*
Approach - Inclusion-Exclusion Approach
Time Complexity      :  O(K)
Space Complexity     :  O(1)
*/
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        int totalWays = 9 * pow(10, n-1);
        int m = 10 - arr.size(); 
        int unwanted = pow(m, n);
        if(find(arr.begin(), arr.end(), 0) == arr.end()){
            unwanted -= pow(m, n-1);
        }
        return totalWays - unwanted;
    }
};
