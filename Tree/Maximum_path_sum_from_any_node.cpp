// problem : https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

/*
Approach-   Divide and conquer
Time Complexity     :  O(N)  
Space Complexity    :  O(h)    where h = height of tree
*/
class Solution {
  public:
    int solve(Node* root,int &ans){
        if(root==NULL) return 0;
        int left = max(0,solve(root->left,ans));
        int right = max(0,solve(root->right,ans));
        
        ans = max(ans,root->data + left + right);
        
        return root->data + max(left,right);
        
        return root->data + temp;
    }
    int findMaxSum(Node *root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
