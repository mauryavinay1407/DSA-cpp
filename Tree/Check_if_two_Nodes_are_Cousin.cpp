// problem:  https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1

/*
Approach:  Level order traversal
Time Comp: O(N)
Space Comp: O(N)
*/

bool isCousins(Node *root, int a, int b) {
   queue<pair<Node*,pair<Node*,int>>> q;
   q.push({root,{nullptr,0}});
   Node* parentofA=nullptr;
   Node* parentofB=nullptr;
   int levelA=-1;
   int levelB=-1;
   while(!q.empty()){
       Node* temp=q.front().first;
       Node* parent=q.front().second.first;
       int level=q.front().second.second;
       q.pop();
       
       if(temp->data==a){
           parentofA=parent;
           levelA=level;
       }
       else if(temp->data==b){
           parentofB=parent;
           levelB=level;
       }
       if(temp->left){
           q.push({temp->left,{temp,level+1}});
       }
       if(temp->right){
           q.push({temp->right,{temp,level+1}});
       }
   }
   return (levelA==levelB && parentofA!=parentofB);
}
