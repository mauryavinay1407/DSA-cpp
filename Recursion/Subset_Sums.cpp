// problem : https://www.geeksforgeeks.org/problems/subset-sums2234/1

/*
Approach-1 : Using recursion
Time Complexity   :  O(2^n)
Space Complexity  :  O(n)   due to recursion stack
*/

class Solution {
  public:
    void solve(vector<int>& arr,int i,int sum,vector<int>& result){
        if(i == arr.size()){
            result.push_back(sum);
            return;
        }
        solve(arr,i+1,sum,result);
        solve(arr,i+1,sum+arr[i],result);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result;
        solve(arr,0,0,result);
        return result;
    }
};
/*
Approach-2 : Iterative method
Time Complexity   :  O(2^n)
Space Complexity  :  O(1)   
*/
class Solution {
public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result = {0}; 
        
        for (int num : arr) {
            int n = result.size();
            for (int i = 0; i < n; i++) {
                result.push_back(result[i] + num);
            }
        }
        return result;
    }
};
