// gfg      :  https://www.geeksforgeeks.org/problems/construct-tree-1/1
// leetcode :  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal 

/*
Approach-1: Using recursion
Time Complexity    :    O(n^2)
Space Complexity   :    O(n)
*/
class Solution {
public:
     int find(vector<int> &inorder,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target)
                return i;
        }
        return -1;
    }
    Node* construct(vector<int> &inorder, vector<int> &preorder,int inStart,int inEnd,int index){
        if(inStart > inEnd){
            return nullptr;
        }
        Node* root=new Node(preorder[index]);
        // for finding the position of root in inorder
        int pos=find(inorder,preorder[index],inStart,inEnd);
        //left
        root->left=construct(inorder,preorder,inStart,pos-1,index+1);
        //right
        root->right=construct(inorder,preorder,pos+1,inEnd,index+(pos-inStart)+1);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        return construct(inorder,preorder,0,n-1,0);
    }
};
/*
Approach-2: Using recursion but more cleaner and a bit optimal due to use of pass by reference to the idx
Time Complexity    :    O(n^2)
Space Complexity   :    O(n)
*/
class Solution {
  public:
    Node* construct(vector<int> &inorder, vector<int> &preorder,int inStart,int inEnd,int& idx){
        if(inStart > inEnd){
            return nullptr;
        }
        int rootValue = preorder[idx];
        int pos = inStart;
        // for finding the position of root in inorder
        for(; pos <= inEnd; pos++){
            if(inorder[pos] == rootValue)
                break;
        }
        Node* root = new Node(rootValue);
        idx++;
        // left
        root->left = construct(inorder,preorder,inStart,pos-1,idx);
        //right
        root->right = construct(inorder,preorder,pos+1,inEnd,idx);
        
        return root;
        }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int idx = 0;
        return construct(inorder,preorder,0,n-1,idx);
    }
};
/*
Approach-3: Using recursion + hash map
Time Complexity    :    O(n)
Space Complexity   :    O(n)
*/
class Solution {
public:
    Node* construct(vector<int> &inorder, vector<int> &preorder,int inStart,int inEnd,int& idx,unordered_map<int,int>& mp){
        if(inStart > inEnd){
            return nullptr;
        }
        int rootValue = preorder[idx];
      // can find the position in O(1)
        int pos = mp[rootValue];
        
        Node* root = new Node(rootValue);
        idx++;
        // left
        root->left = construct(inorder,preorder,inStart,pos-1,idx,mp);
        //right
        root->right = construct(inorder,preorder,pos+1,inEnd,idx,mp);
        
        return root;
        }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int idx = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return construct(inorder,preorder,0,n-1,idx,mp);
    }
};
