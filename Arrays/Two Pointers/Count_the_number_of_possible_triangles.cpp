// problem : https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

/*
Approach-1 : Brute Force
Time Complexity    :  O(N^3)
Space Complexity   :  O(1)
*/
class Solution {
public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        // Iterate over all triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Check if the triplet forms a triangle
                    if (arr[i] + arr[j] > arr[k] &&
                        arr[i] + arr[k] > arr[j] &&
                        arr[j] + arr[k] > arr[i]) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
/*
Approach-2 : Optimal using sorting and two pointer
Time Complexity    :  O(N^2)
Space Complexity   :  O(1)
*/
class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int result = 0;
        int i=n - 1;
        while(i > 1){
            int start = 0;
            int end = i - 1;
            while(start < end){
                if(arr[start] + arr[end] > arr[i]){
                    result += end - start;
                    end--;
                }
                else 
                    start++;
            }
            i--;
        }
        return result;
    }
};
