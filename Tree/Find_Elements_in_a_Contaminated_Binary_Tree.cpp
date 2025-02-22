// problem : https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree

/*
Approach- using unordered set
Time Complexity    :  O(N)
Space Complexity   :  O(N)
*/

class FindElements {
public:
    unordered_set<long long> st;
    FindElements(TreeNode* root) {
        if (!root)
            return;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        st.insert(0);
        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            long long count = q.front().second;
            q.pop();
            if (temp->left) {
                long long t = 2 * count + 1;
                q.push({temp->left, t});
                st.insert(t);
            }
            if (temp->right) {
                long long t = 2 * count + 2;
                q.push({temp->right, t});
                st.insert(t);
            }
        }
    }

    bool find(int target) {
        return st.count(target); 
    }
};
