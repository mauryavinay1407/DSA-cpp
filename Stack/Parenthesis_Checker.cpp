// problem : https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

/*
Approach- Using Stack
Time Complexity    :  O(N)
Space Complexity   :  O(N)
*/
class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;
        for(auto& b : s){
            if(b == '(' || b == '{' || b == '['){
                st.push(b);
            }
            else{
                if(st.empty() || st.top() == '(' && b!=')' || st.top() == '{' && b!='}' || st.top() == '[' && b!=']'){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
