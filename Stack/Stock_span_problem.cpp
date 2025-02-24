// problem  : https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

/*
Approach- Using Stack
Time Complexity       :   O(N)
Space Complexity      :   O(N)
*/

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n,1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                while(!st.empty() && arr[i] > arr[st.top()]){
                    result[st.top()] = st.top() - i;
                    st.pop();
                }
            }
            st.push(i);
        }
        while(!st.empty()){
            result[st.top()] = st.top() + 1;
            st.pop();
        }
        return result;
    }
};
