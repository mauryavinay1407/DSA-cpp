// problem :   https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves

/*
Approach - Finding depth then LCA
Time Complexity     :  O(N) 
Space Complexity    :  O(logN)
*/

class Solution {
public:
    unordered_map<TreeNode*, int> mp;
    int maxDepth = 0;
    void findDepth(TreeNode* root, int d) {
        if (!root)
            return;
        mp[root] = d;
        maxDepth = max(maxDepth, d);
        findDepth(root->left, d + 1);
        findDepth(root->right, d + 1);
    }

    TreeNode* LCA(TreeNode* root, int d) {
        if (!root || d == maxDepth) {
            return root;
        }
        TreeNode* leftLCA = LCA(root->left, d + 1);
        TreeNode* rightLCA = LCA(root->right, d + 1);

        if (leftLCA && rightLCA) {
            return root;
        }
        return leftLCA ? leftLCA : rightLCA;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        findDepth(root, 0);
        return LCA(root, 0);
    }
};
