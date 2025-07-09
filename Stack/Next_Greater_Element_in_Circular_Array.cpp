// problem   :   https://www.geeksforgeeks.org/problems/next-greater-element/1

/*
Approach-1: Using Stack
Time Complexity        :  O(N)
Space Complexity       :  O(N)
*/

class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> result(n,-1);
        stack<int> st;
        for(int i = 0; i < 2 * n; i++){
            while(!st.empty() && arr[i % n] > arr[st.top() % n]){
                result[st.top() % n] = arr[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        
        return result;
    }
};
