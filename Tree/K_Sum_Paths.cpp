// problem : https://www.geeksforgeeks.org/problems/k-sum-paths/1

/*
Approach - Divide and conquer using prefix sum and map
Time Complexity    :  O(N)
Space Complexity   :  O(N)
*/

class Solution {
  public:
     void solve(Node* root, int sum, int k, unordered_map<int, int>& prefixSum,int& ans) {
        if (!root) return;

        sum += root->data;
        if (prefixSum.count(sum-k)) {
            ans += prefixSum[sum - k];
        }

        prefixSum[sum]++;
        
        solve(root->left, sum, k, prefixSum,ans);
        solve(root->right, sum, k, prefixSum,ans);

        prefixSum[sum]--;
    }
    int sumK(Node *root, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1; 
        int ans = 0;
        solve(root, 0, k, prefixSum,ans);
        return ans;
    }
};
