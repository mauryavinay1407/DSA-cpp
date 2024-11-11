// problem: https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1

/*
Approach-1: Brute force(Using sorting and set to store unique elements and check their occurence)
Time Complexity:    O(N^2)
Space Complexity:   O(N)
*/
class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        unordered_set<int> st;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
            st.insert(arr[i]);
        int result = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] == arr[i-1]){
                int x=arr[i];
                while(st.count(x))
                    x++;
                st.insert(x);
                result += (x - arr[i]);
            }
        }
        return result;
    }
};

/*
Approach-2: optimal using sorting
Time Complexity:    O(N*logN)
Space Complexity:   O(1)
*/
class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int result = 0;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i-1] >= arr[i]){
                int incr = arr[i - 1] - arr[i] + 1;
                result += incr ;
                arr[i] += incr;
            }
        }
        return result;
    }
};
