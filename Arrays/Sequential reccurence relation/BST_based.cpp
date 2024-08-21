struct Node {
    int val;
    int cnt;
    Node* left;
    Node* right;

    Node(int val) : val(val), cnt(1), left(nullptr), right(nullptr) {}
};

// The searching and insertion operations can be done as follows:
class Solution {
  public:
int search(Node root, long val) {
    if (root == null) {
    	return 0;
    } else if (val == root->val) {
    	return root->cnt;
    } else if (val < root->val) {
    	return root->cnt + search(root->left, val);
    } else {
    	return search(root->right, val);
    }
}
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        root = new Node(val);
    } else if (val == root->val) {
        root->cnt++;
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->cnt++;
        root->right = insert(root->right, val);
    }
    return root;
}
// Note: this homemade BST is not self-balanced and the time complexity can go as bad as O(n^2) .To guarantee O(nlogn) performance, use one of the self-balanced BST's (e.g. Red-black tree, AVL tree, etc.).
int reversePairs(std::vector<int>& nums) {
    int res = 0;
    Node* root = nullptr; 	
    for (int ele : nums) {
        res += search(root, 2L * ele + 1);
        root = insert(root, ele);
    } 
    return res;
}
   };
