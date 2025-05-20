// problem  :   https://www.geeksforgeeks.org/problems/burning-tree/1

/*
Approach - DFS + Backtracking
Time Complexity       :   O(N)
Space Complexity      :   O(N)
*/
class Solution {
public:
  
    int BurnTree(Node* root,int& timer,int target){
        if(!root){
            return 0;
        }
        // root exists
        if(root->data == target){
            return -1;
        }
        int left = BurnTree(root->left,timer,target);
        int right = BurnTree(root->right,timer,target);
        
        if(left < 0){
            timer = max(timer,abs(left) + right);
            return left - 1;
        }
        if(right < 0){
            timer = max(timer,abs(right) + left);
            return right - 1;
        }
        
        return 1 + max(left,right);
    }
    
    void find(Node* root,int target,Node* &BurnNode){
        if(!root){
            return;
        }
        if(root->data == target){
            BurnNode = root;
            return;
        }
        find(root->left,target,BurnNode);
        find(root->right,target,BurnNode);
    }
    
    int height(Node* root){
        if(!root){
            return 0;
        }
        return 1 + max(height(root->left),height(root->right));
    }
    
    int minTime(Node* root, int target) {
        // code here
        int timer=0;
        BurnTree(root,timer,target);
        
        Node *BurnNode = NULL;
        find(root,target,BurnNode);
        
        int high = height(BurnNode) - 1;
        
        return max(timer,high);
    }
};
