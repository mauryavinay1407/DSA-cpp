// problem: https://leetcode.com/problems/diameter-of-binary-tree/description

// Appraoch-1

class Solution {
public:
    int height(TreeNode* root){
        if(!root)
        return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;
        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
       int curr=height(root->left)+height(root->right);
       return max({curr,left,right});
    }
};

// Approach-2

class Solution {
public:
    int maxDia=INT_MIN;
    int height(TreeNode* root){
        if(!root)
        return 0;
        int left=height(root->left);
        int right=height(root->right);
        maxDia=max(maxDia,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;
       height(root);
       return maxDia;
    }
};
