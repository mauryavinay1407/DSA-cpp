// problem : https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

/*
Approach-1:   Using set
Time Complexity        :  O(N*logN)
Space Complexity       :  O(N)
*/
class Solution {
public:
    int missingNumber(vector<int> &arr) {
        set<int> st(arr.begin(),arr.end());
        int prev = 0;
        for(auto& s : st){
            if(s > 0){
                if(s == prev + 1){
                    prev = s;
                }else{
                    return prev + 1;
                }
            }
        }
        return prev + 1;
    }
};
/*
Approach-1:   Using sorting without extra space
Time Complexity        :  O(N*logN)
Space Complexity       :  O(1)
*/
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int missing = 1; 
        for (int num : nums) {
            if (num == missing) {
                missing++; 
            }
        }
        return missing;
    }
};
