// problem :  https://leetcode.com/problems/flip-equivalent-binary-trees/description/

/*
Approach:  Using recursion
Time Complexity:   O(N)
Space Complexity:  O(N)
*/

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        if (root1->val != root2->val)
            return false;

        if ((flipEquiv(root1->left, root2->left) ||
             flipEquiv(root1->left, root2->right)) &&
            (flipEquiv(root1->right, root2->left) ||
             flipEquiv(root1->right, root2->right)))
            return true;
        return false;
    }
};
