// problem  :  https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

/*
Approach - Using 2 loops and set
Time Complexity      :  O(N^2)
Space Complexity     :  O(N)
*/
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        unordered_set<int> st;
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]*arr[i]);
        }
        
        for(int i=0;i<arr.size()-1;i++){
            for(int j=1;j<arr.size();j++){
                if(st.count(arr[i]*arr[i] + arr[j]*arr[j])){
                    return true;
                }
            }
        }
        
        return false;
    }
};
