// problem : https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1

/*
Approach-1: Brute force  (TLE)
Time Complexity    :  O(N^3)
Space Complexity   :  O(1)
*/
class Solution {
public:
    int countTriplets(vector<int>& arr, int target) {
        int n = arr.size();
        int result = 0;

        // Iterate through all possible triplets using 3 nested loops
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == target) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};
/*
Approach-2: Better using loops + binary search (TLE)
Time Complexity    :  O(N^2 * logN)
Space Complexity   :  O(1)
*/
class Solution {
  public:
   int countTriplets(vector<int>& arr, int target) {
    int n = arr.size();
    int result = 0;
    
    for(int i=0; i < n-2; i++){
        for(int j=i+1; j < n-1; j++){
            int tSum = target - (arr[i] + arr[j]);
            
            auto low = lower_bound(arr.begin() + j + 1,arr.end(),tSum);
            auto high = upper_bound(arr.begin() + j + 1,arr.end(),tSum);
            
            result += (high - low);
        }
    }
    return result;
    }
};
/*
Approach-3: Optimal using two pointer
Time Complexity    :  O(N^2)
Space Complexity   :  O(1)
*/
class Solution {
  public:
   int countTriplets(vector<int>& arr, int target) {
    int n = arr.size();
    int result = 0;
    
    for(int i = 0; i < n - 2; i++) {
        int x = target - arr[i];
        int start = i + 1;
        int end = n - 1;
        
        while(start < end) {
            if(arr[start] + arr[end] > x)
                end--;
            else if(arr[start] + arr[end] < x)
                start++;
            else {
                // Found a match
                if(arr[start] == arr[end]) {
                    // If all elements between start and end are same
                    int count = end - start + 1;
                    result += (count * (count - 1)) / 2;
                    break;
                }
                
                // Count duplicates at start
                int startCount = 1;
                while(start + 1 < end && arr[start] == arr[start + 1]) {
                    startCount++;
                    start++;
                }
                
                // Count duplicates at end
                int endCount = 1;
                while(end - 1 > start && arr[end] == arr[end - 1]) {
                    endCount++;
                    end--;
                }
                
                // Add combinations of duplicates
                result += startCount * endCount;
                start++;
                end--;
            }
        }
    }
    
    return result;
}
};
