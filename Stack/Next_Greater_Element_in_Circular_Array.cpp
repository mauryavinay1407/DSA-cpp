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
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }
};
