// problem  :  https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1


/*
Approach - Using two pointers
Time Complexity      : O(N^2)
Space Complexity     : O(N)
*/
class Solution {
public:
    vector<int> find(vector<int>& preorder,int start,int end){
        if(start == end){
            return {preorder[start]};
        }
        if(start > end){
            return {};
        }
        int curr = preorder[start];
        int i = start+1;
        
        while(i <= end && preorder[i] < curr){
            i++;
        }
        
        vector<int> leftLeaf = find(preorder,start+1,i-1);
        vector<int> rightLeaf = find(preorder,i,end);
        
        for(auto& it : rightLeaf){
            leftLeaf.push_back(it);
        }
        
        return leftLeaf;
    }
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        return find(preorder,0,preorder.size()-1);
    }
};
