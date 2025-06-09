// problem  :  https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

/*
Approach - Using Preorder + range tracking
Time Complexity       :  O(N)
Time Complexity       :  O(1)
*/

class Solution {
public:
    bool findDead(Node* root,int pre,int next){
        if(!root){
            return false;
        }
        
        if((root->data == pre + 1 || root->data - 1 == 0) &&
            (root->data == next - 1 || root->data + 1 == 100000)){
                return true;
            }
        
        
        return findDead(root->left,pre,root->data)||findDead(root->right,root->data,next);
        
    }
    bool isDeadEnd(Node *root) {
        // Code here
        int pre = INT_MIN;
        int next = INT_MAX;
        return findDead(root,pre,next);
    }
};
