// problem: https://www.geeksforgeeks.org/problems/check-for-bst/1

/*
Approach-1: Using inOrder i.e we know that inorder of a bst is in sorted order
Time Complexity: O(n)
Time Complexity: O(n)
*/

class Solution {
  public:
      void inOrder(Node* root,vector<int>& res){
     if(!root)
       return;
     inOrder(root->left,res);
     res.push_back(root->data);
     inOrder(root->right,res);
    }   
    
    bool isBST(Node* root) {
     vector<int> res;
      inOrder(root,res);
      for(int i=1;i<res.size();i++){
        if(res[i]<=res[i-1])
          return false;
      }
      return true;
    }  
};


/*
Approach-2: Using a prev variable as we know that left child is always less than right child
Time Complexity: O(n)
Time Complexity: O(1)  excluding recursive stack for height of tree
*/

class Solution {
  public:
    bool BST(Node* root,int& prev){
        if(!root)
        return true;
        
        if(!BST(root->left,prev))
        return false;
        
        if(root->data<=prev)
         return false;
        
        prev=root->data;
        
        return BST(root->right,prev);
    }
    bool isBST(Node* root) {
     int prev=INT_MIN;
     return BST(root,prev);
    }
};
