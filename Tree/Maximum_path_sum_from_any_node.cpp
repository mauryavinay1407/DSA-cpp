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
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int temp=max(0,max(left,right));
        ans=max(ans,max(root->data+left+right ,root->data+temp));
        
        return root->data + temp;
    }
    int findMaxSum(Node *root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
