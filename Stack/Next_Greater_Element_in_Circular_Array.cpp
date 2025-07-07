// problem   :   https://www.geeksforgeeks.org/problems/next-greater-element/1

/*
Approach - Using Stack
Time Complexity        :  O(N)
Space Complexity       :  O(N)
*/

class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> result(n, -1);
        for(int i = 2*n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i % n]){
                st.pop();
            }
            if(i < n && !st.empty()){
                result[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return result;
    }
};
