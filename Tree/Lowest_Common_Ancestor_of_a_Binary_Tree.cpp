// problem : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/*
Approach - Using Recursive DFS
Time Complexity   : O(N)
Space Complexity  : O(logN)
*/

class Solution {
public:
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
       if(!root || root==p || root==q)
       return root;
       TreeNode* leftLCA=findLCA(root->left,p,q);
       TreeNode* rightLCA=findLCA(root->right,p,q);

       if(leftLCA && rightLCA) 
       return root;

       return (leftLCA) ? leftLCA : rightLCA;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return findLCA(root,p,q);
    }
};
