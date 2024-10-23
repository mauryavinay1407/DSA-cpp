// problem:  https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

/*
Approach: Using Level Order Traversal
Time Complexity:    O(N)
Space Complexity:   O(N)
*/

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            vector<TreeNode*> nodes;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                nodes.push_back(temp);
                if (temp->left) {
                    q.push(temp->left);
                    sum += temp->left->val;
                }
                if (temp->right) {
                    q.push(temp->right);
                    sum += temp->right->val;
                }
            }
            for (auto& node : nodes) {
                int total = sum;
                if (node->left)
                    total -= node->left->val;
                if (node->right)
                    total -= node->right->val;
                if (node->left)
                    node->left->val = total;
                if (node->right)
                    node->right->val = total;
            }
        }
        return root;
    }
};
