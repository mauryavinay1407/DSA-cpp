// problem : https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

/*
Approach- Using stack
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/ 

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and arr[st.top()] > arr[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            right[st.top()] = n;
            st.pop();
        }
        for(int i = n - 1; i >= 0 ; i--){
            while(!st.empty() and arr[st.top()] > arr[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            left[st.top()] = -1;
            st.pop();
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, arr[i] * (right[i] - left[i] -1));
        }
        return ans;

    }
};
