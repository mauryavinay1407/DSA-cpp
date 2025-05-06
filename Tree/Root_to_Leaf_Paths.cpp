//  problem  : https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*
Approach - Using backtracking
Time Complexity      :  O(N)
Space Complexity     :  O(H + L*H) where N = total nodes, H = tree height, L = number of leaf nodes.
*/

class Solution {
  public:
    void findPaths(Node* root,vector<vector<int>>& result,vector<int>& temp){
        temp.push_back(root->data);
        if(!root->left && !root->right){
            result.push_back(temp);
            return;
        }
        if(root->left){
            findPaths(root->left,result,temp);
            temp.pop_back();
        }
        if(root->right){
            findPaths(root->right,result,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> temp;
        findPaths(root,result,temp);
        return result;
    }
};
