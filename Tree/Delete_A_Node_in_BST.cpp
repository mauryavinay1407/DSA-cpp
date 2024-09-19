// problem:  https://leetcode.com/problems/delete-node-in-a-bst/description/


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
     if(!root)
     return NULL;
    
    if(root->val>key){
     root->left=deleteNode(root->left,key);
    }
    else if(root->val<key){
       root->right=deleteNode(root->right,key);
    }
    else{
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        if(!root->left){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        if(!root->right){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        TreeNode* child=root->left;
        TreeNode* parent=root;
        while(child->right){
         parent=child;
         child=child->right;
        }
        if(parent==root){
           child->right = root->right;
           delete root;
           return child;
        }
        else{
            parent->right=child->left;
            child->left=root->left;
            child->right=root->right;
            delete root;
            return child;
        }
    }
    return root;
    }
};
