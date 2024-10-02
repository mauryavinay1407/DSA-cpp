// problem:  https://www.naukri.com/code360/problems/create-binary-tree_8360671

Node* builTree(int i,vector<int>&arr){
    if(i>=arr.size())
     return NULL;

     Node* root=new Node(arr[i]);

     root->left=builTree(2*i+1,arr);
     root->right=builTree(2*i+2,arr);
     return root;
}

Node* createTree(vector<int>&arr){
    return builTree(0,arr);
}
