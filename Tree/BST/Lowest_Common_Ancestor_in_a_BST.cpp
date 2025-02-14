// gfg :         https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
// leetcode :    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/*
Approach- Using recursion
Time Complexity   :   O(H)
Space Complexity  :   O(H)            where H = height of tree
*/

class Solution {
  public:
    Node* find(Node* root, Node* n1, Node* n2){
        if(root->data > n1->data && root->data > n2->data)
            return find(root->left,n1,n2);
        else if(root->data < n1->data && root->data < n2->data)
            return find(root->right,n1,n2);
        else
            return root;
    }
    Node* LCA(Node* root, Node* n1, Node* n2) {
        return find(root,n1,n2);
    }
};
