// problem  :  https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1

/*
Approach - Using stack
Time Complexity       :    O(N)
Space Complexity      :    O(N)
*/
class Solution {
public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        int n = color.size();
        stack<pair<int,int>> st;
        
        int i=0;

        while(i < n){
            if(!st.empty() && st.top() == make_pair(color[i],radius[i])){
                while(!st.empty() && st.top() == make_pair(color[i],radius[i])){
                    st.pop();
                    i++;
                }
                continue;
            }   
            st.push({color[i],radius[i]});
            i++;
        }
        return st.size();
    }
};
