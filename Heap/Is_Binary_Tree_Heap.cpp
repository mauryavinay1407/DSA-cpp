// problem  :  https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

/*
Approach -  Using queue
Time Complexity      :  O(N)
Space Complexity     :  O(N)
*/
class Solution {
public:
    bool isComplete(Node* root){
        if(root==NULL) return true;
        string ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                if(temp->data==-1){
                    ans+='N';
                    continue;
                }
                ans+=to_string(temp->data);
                if(temp->left) q.push(temp->left);
                else q.push(new Node(-1));
                if(temp->right) q.push(temp->right);
                else q.push(new Node(-1));
            }
        }
        int val = 0;
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]!='N') val = 1;
            if(val==1 && ans[i]=='N') return false;
        }
        return true;
    }
    
    bool isMax(Node* root,int a,Node* temp){
        if(temp==NULL) return true;
        else if(temp->data>a) return false;
        else
        return isMax(temp,temp->data,temp->left) && isMax(temp,temp->data,temp->right);
    }
    
    bool isHeap(Node* tree) {
        // code here
        if(tree==NULL) return true;
        bool a = isComplete(tree);
        bool b = isMax(tree,tree->data,tree->left) && isMax(tree,tree->data,tree->left);
        return a&&b;
    }
};
