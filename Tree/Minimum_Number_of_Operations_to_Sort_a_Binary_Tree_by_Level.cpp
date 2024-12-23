// problem:  https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level

/*
Approach - BFS + Minimum operations to sort an array excluding duplicate element
Time Complexity  :  O(N*logN)
Space Complexity :  O(N)
*/
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swaps = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> nodes;
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                nodes.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            unordered_map<int, int> mp;
            for (int i = 0; i < nodes.size(); i++) {
                mp[nodes[i]] = i;
            }
            vector<int> sortedNodes = nodes;
            sort(begin(sortedNodes), end(sortedNodes));
            for (int i = 0; i < sortedNodes.size(); i++) {
                if (sortedNodes[i] != nodes[i]) {
                    swaps++;
                    int idx = mp[sortedNodes[i]];
                    mp[nodes[i]] = idx;
                    mp[nodes[idx]] = i;
                    swap(nodes[i], nodes[idx]);
                }
            }
        }
        return swaps;
    }
};
