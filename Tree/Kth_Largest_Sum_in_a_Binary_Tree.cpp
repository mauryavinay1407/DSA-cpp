// problem:  https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

/*
Approach: Using level order traversal
Time Complexity: O(N*logK)
Space Complexity: O(N)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    using ll = long long;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        queue<TreeNode*> q;
        ll l = 0;
        q.push(root);
        while (!q.empty()) {
            ll size = q.size();
            ll sum = 0;
            l++;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            pq.push(sum);
            if (pq.size() > k)
                pq.pop();
        }
        return (l >= k) ? pq.top() : -1;
    }
};
