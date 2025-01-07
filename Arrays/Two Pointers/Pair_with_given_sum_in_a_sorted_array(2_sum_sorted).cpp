// problem: https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1

/*
Approach-1: Brute force  (TLE)
Time Complexity    :  O(N^2)
Space Complexity   :  O(1)
*/
class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int result = 0;

        // Iterate through all possible triplets using 3 nested loops
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] + arr[j] == target) {
                        result++;
                    }
                }
            }

        return result;
    }
};

/*
Approach-2: Better using loops + binary search 
Time Complexity    :  O(N * logN)
Space Complexity   :  O(1)
*/
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int result = 0;
    
        for(int i=0; i < n-1; i++){
            int tSum = target - arr[i];
            
            auto low = lower_bound(arr.begin() + i + 1,arr.end(),tSum);
            auto high = upper_bound(arr.begin() + i + 1,arr.end(),tSum);
            
            result += (high - low);
        }
        return result;
    }
};

/*
Approach-3: Optimal using two pointer
Time Complexity    :  O(N)
Space Complexity   :  O(1)
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int result = 0;
        int i=0;
        int j=arr.size()-1;
        while(i < j){
            if(arr[i] + arr[j] < target)
                i++;
            else if(arr[i] + arr[j] > target)
                j--;
            else{
                if(arr[i] == arr[j]){
                    int count = j - i + 1;
                    result += (count*(count-1))/2;
                    break;
                }
                int startCount = 1;
                while(i < j + 1 && arr[i] == arr[i + 1]){
                    startCount++;
                    i++;
                }
                int endCount = 1;
                while(j - 1 > i && arr[j] == arr[j - 1]){
                    endCount++;
                    j--;
                }
                result += startCount*endCount;
                i++;
                j--;
            }
        }
        return result;
    }
};
