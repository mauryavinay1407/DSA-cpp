// problem : https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

/*
Approach - 1 : Brute force using Set
Time Complexity    :  O(log N) for push/pop
Space Complexity   :  O(N)
*/
class Solution {
public:
    stack<int> st;
    set<int> s;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        st.push(x);
        s.insert(x);
    }

    // Remove the top element from the Stack
    void pop() {
        if(st.empty()) return;
        int temp = st.top();
        st.pop();
        s.erase(temp);
    }

    // Returns top element of the Stack
    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty()) return -1;
        return *s.begin();
    }
};
/*
Approach - 2 :  Optimize using one extra stack
Time Complexity    :  O(1) for all operations
Space Complexity   :  O(N)
*/
class Solution {
public:
    stack<int> st;
    stack<int> minSt; // Stack to track minimums

    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (st.empty()) return;
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }
};
