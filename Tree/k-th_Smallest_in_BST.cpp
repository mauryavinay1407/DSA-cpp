// problem : https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

/*
Approach-1 : Using max-heap
Time Complexity     :  O(n * logk)
Space Complexity    :  O(k)
*/
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void find(Node* root,priority_queue<int>& pq,int k){
        if(!root ){
            return;
        }
        find(root->left,pq,k);
        pq.push(root->data);
        if(pq.size() > k)
            pq.pop();
        find(root->right,pq,k);
    }
    int kthSmallest(Node *root, int k) {
        priority_queue<int> pq;
        find(root,pq,k);
        if(pq.size() < k)
            return -1;
        return pq.top();
    }
};
/*
Approach-2 : Using stack
Time Complexity     :  O(n)
Space Complexity    :  O(H)   where H = height of tree
*/
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node* root, int k) {
    stack<Node*> st;
    Node* curr = root;
    
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;  
        }

        curr = st.top();
        st.pop();
        k--;

        if (k == 0) return curr->data;  

        curr = curr->right;  
    }
    return -1; 
}
};
/*
Approach-3 : Using recursion
Time Complexity     :  O(n)
Space Complexity    :  O(H)   where H = height of tree
*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int& k) {
        if(!root)
            return -1;
        int left = kthSmallest(root->left,k);
        if(left != -1) return left;
        k--;
        if(k == 0) return root->data;
        return kthSmallest(root->right,k);
    }
};
