// problem  :  https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

/*
Approach- Using Stack
Time Complexity       :   O(N)
Space Complexity      :   O(N)
*/


class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n,-1);
        stack<int> st;
        result[n-1] = -1;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

