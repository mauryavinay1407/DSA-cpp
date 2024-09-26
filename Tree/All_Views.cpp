/*Left Side View of a Binary Tree */

// link:  https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Time: O(n)
// Space: O(n)

vector<int> leftView(Node *root)
{
   if(!root)
   return {};
   vector<int> result;
   queue<pair<Node*,int>> q;
   q.push({root,0});
   
   while(!q.empty()){
      Node* temp=q.front().first;
      int level=q.front().second;
      q.pop();
      if(q.empty()){
          result.push_back(temp->data);
      }
      else if(level<q.front().second){
          result.push_back(temp->data);
      }
      if(temp->right)
       q.push({temp->right,level+1});
      if(temp->left)
       q.push({temp->left,level+1});
   }
   return result;
}


/*Right Side View of a Binary Tree */

// link:  https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1

// Time: O(n)
// Space: O(n)

 vector<int> rightView(Node *root)
    {
      if(!root)
      return {};
      vector<int> result;
      queue<pair<Node*,int>> q;
      q.push({root,0});
   while(!q.empty()){
      Node* temp=q.front().first;
      int level=q.front().second;
      q.pop();
      if(q.empty()){
          result.push_back(temp->data);
      }
      else if(level<q.front().second){
          result.push_back(temp->data);
      }
      if(temp->left)                             // nothing much different than left side ,just change the child insertion i.e push the left child first in queue
       q.push({temp->left,level+1});
      if(temp->right)
       q.push({temp->right,level+1});
   }
   return result;
    }

/* Top View of a Binary Tree  */

// link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Time: O(n)
// Space: O(n)

void find(Node* root,int pos,int& l,int& r){
        if(!root)
        return;
        l=min(l,pos);
        r=max(r,pos);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    vector<int> topView(Node *root)
    {
      int l=0,r=0;
      find(root,0,l,r);
      vector<int> result(r-l+1,0);
      vector<bool> visited(r-l+1,0);
      queue<pair<Node*,int>> q;
      q.push({root,-l});
      while(!q.empty()){
          Node* temp=q.front().first;
          int level=q.front().second;
          q.pop();
          if(!visited[level]){
          result[level]=temp->data;
           visited[level]=true;
          }
          
          if(temp->left){
              q.push({temp->left,level-1});
          }
          if(temp->right){
              q.push({temp->right,level+1});
          }
      }
      return result;
    }

/* Bottom View of a Binary Tree*/

// link:  https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Time: O(n)
// Space: O(n)

 void find(Node* root,int pos,int& l,int& r){
        if(!root)
        return;
        l=min(l,pos);
        r=max(r,pos);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    vector<int> bottomView(Node *root)
    {
      int l=0,r=0;
      find(root,0,l,r);
      vector<int> result(r-l+1,0);
      vector<bool> visited(r-l+1,0);
      queue<pair<Node*,int>> q;
      q.push({root,-l});
      while(!q.empty()){
          Node* temp=q.front().first;
          int level=q.front().second;
          q.pop();
          if(!visited[level]){
          result[level]=temp->data;   // just change the line which were marking the visited node in top view
          }
          
          if(temp->left){
              q.push({temp->left,level-1});
          }
          if(temp->right){
              q.push({temp->right,level+1});
          }
      }
      return result;
    }
