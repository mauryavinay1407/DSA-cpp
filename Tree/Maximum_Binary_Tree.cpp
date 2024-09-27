// problem:  https://leetcode.com/problems/maximum-binary-tree/description/

/*
Approach :   Divide and conquer
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    TreeNode* buildMaxTree(vector<int>& nums,int l,int r){
        if(l>r)
        return NULL;
        auto maxIt=max_element(nums.begin()+l,nums.begin()+r+1);
        int maxElement=*maxIt;
        int index=distance(nums.begin(),maxIt);

        TreeNode* root=new TreeNode(maxElement);
        root->left=buildMaxTree(nums,l,index-1);
        root->right=buildMaxTree(nums,index+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return buildMaxTree(nums,0,n-1);
    }
};
