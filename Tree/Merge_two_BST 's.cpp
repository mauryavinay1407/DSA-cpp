// problem:  https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

/*
Approach-1: inOrder + merge two sorted arrays
Time Complexity: O(N1+N2)
Space Complexity: O(N1+N2)
*/

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inOrder(vector<int>& arr,Node* root){
        if(!root)
         return;
        inOrder(arr,root->left);
        arr.push_back(root->data);
        inOrder(arr,root->right);
    }
    
    vector<int> mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2){
        int i=0;
        int j=0;
        vector<int> mergedArray;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]) 
               mergedArray.push_back(arr1[i++]);
            else
               mergedArray.push_back(arr2[j++]);
        }
        while(i<arr1.size())
           mergedArray.push_back(arr1[i++]);
        while(j<arr2.size())
           mergedArray.push_back(arr2[j++]);
         
     return mergedArray;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
     
     vector<int> arr1;
     vector<int> arr2;
     
     inOrder(arr1,root1);
     inOrder(arr2,root2);
     
     return mergeTwoSortedArrays(arr1,arr2);
    }
};
