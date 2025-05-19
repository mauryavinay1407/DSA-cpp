// problem  :  https://www.geeksforgeeks.org/problems/predecessor-and-successor/1


/*
Approach - Using inorder traversal
Time Complexity          :  O(N)
Space Complexity         :  O(h)   where h = height of tree
*/

class Solution {
public:
    Node* prev=NULL;
    Node* next=NULL;
    int smaller = INT_MIN;
    int greater = INT_MAX;
    void find(Node* root,int key){
        if(!root){
            return;
        }
        if(root->data < key && smaller < root->data){
            smaller = root->data;
            prev = root;
        }
        else if(root->data > key && greater > root->data){
            greater = root->data;
            next = root;
        }
        find(root->left,key);
        find(root->right,key);
        
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        find(root,key);
        return {prev,next};
    }
};
