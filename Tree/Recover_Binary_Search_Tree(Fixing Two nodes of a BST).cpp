// leetcode : https://leetcode.com/problems/balanced-binary-tree
// gfg      : https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

/*
Approach-1:  Brute Force using first sort the nodes and then place them
Time Complexity    :  O(N*log N)    due to sorting
Space Complexity   :  O(N) + O(Height of tree) ~ O(N)      - due to storing all nodes and the height for the recursion stack, where h is the height of the tree. 
*/
class Solution {
public:
    void inorder(struct Node* root,vector<int>& nodes){
        if(!root)
            return;
        inorder(root->left,nodes);
        nodes.push_back(root->data);
        inorder(root->right,nodes);
    }
    
    void buildBST(struct Node* root,vector<int>& nodes,int& index){
        if(!root)
            return;
        buildBST(root->left,nodes,index);
        root->data = nodes[index++];
        buildBST(root->right,nodes,index);
    }
    void correctBST( struct Node* root )
    {
        vector<int> nodes;
        inorder(root,nodes);
        sort(nodes.begin(),nodes.end());
        int index = 0;
        buildBST(root,nodes,index);
    }
};

/*
Approach-2:  Better using inorder traversal
Time Complexity   :  O(N)
Space Complexity  :  O(h) height for the recursion stack, where h is the height of the tree.
*/
class Solution {
public:
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        if (prev && root->val < prev->val) {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second)
            swap(first->val, second->val);
    }
};
/*
Approach-3:  Optimal using Morris traversal
Time Complexity   :  O(N)
Space Complexity  :  O(1) 
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = NULL;
        TreeNode* first = NULL,*second=NULL;
        TreeNode* last = NULL,*present=NULL;
        
        while(root){
            if(!root->left){
                last = present;
                present = root;
                if(last && last->val > present->val){
                    if(!first)
                        first = last;
                    second = present;
                }
                root = root->right;
            }
            else{
                curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }
                
                if(!curr->right){
                    curr->right = root;
                    root = root->left;
                }
                else{
                    curr->right = NULL;
                    last = present;
                    present = root;
                    
                    if(last && last->val > present->val){
                        if(!first)
                            first = last;
                        second = present;
                    }
                    root = root->right;
                }
            }
        }
        swap(first->val,second->val);
    }
};
