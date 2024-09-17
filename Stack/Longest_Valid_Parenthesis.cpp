// problem:  https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

/*
Approach-1  (Using StacK)
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
  public:
    int maxLength(string& str) {
        // code here
    stack<int> st;  
    int maxLength = 0;
    st.push(-1);  

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push(i); 
        } else {
            st.pop();  
            
            if (!st.empty()) {
                maxLength = max(maxLength, i - st.top());
            } else {
                st.push(i);  
            }
        }
    }
    return maxLength;   
    }
};


/*
Approach-1  (Using Two Pass)
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
  public:
   int maxLength(string& str) {
    int left = 0, right = 0;
    int maxLength = 0;

    // Left to Right 
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') left++;
        else right++;
        
        if (left == right) {
            maxLength = max(maxLength, 2 * right); // Valid substring found
        } else if (right > left) {
            left = right = 0;  // Reset counters when invalid substring found
        }
    }

    left = right = 0; // Reset counters for second pass

    // Right to Left 
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '(') left++;
        else right++;

        if (left == right) {
            maxLength = max(maxLength, 2 * left); // Valid substring found
        } else if (left > right) {
            left = right = 0;  // Reset counters when invalid substring found
        }
    }

    return maxLength;
}

};

