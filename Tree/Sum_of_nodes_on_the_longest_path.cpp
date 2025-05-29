//  problem  :  https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*
Approach - Using preorder traversal
Time Complexity        :   O(N)
Space Complexity       :   O(H)             where H = height of tree
*/

class Solution {
public:
    void preOrder(Node* curr, int sum, int& ans, int len, int& maxLen){
        if(curr == NULL){
            if(len > maxLen){
                ans = sum;
                maxLen = len;
            }
            else if(len == maxLen){
                ans = max(sum, ans);
            }
            
            return;
        }
        
        preOrder(curr -> left, sum + curr -> data, ans, len+1, maxLen);
        preOrder(curr -> right, sum + curr -> data, ans, len+1, maxLen);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int ans = 0;
        int maxLen = 0;
        
        preOrder(root, 0, ans, 0, maxLen);
        return ans;
    }    
};
