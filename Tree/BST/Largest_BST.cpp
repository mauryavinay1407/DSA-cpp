// problem: https://www.geeksforgeeks.org/problems/largest-bst/1

/*
Time Complexity:  O(N)
space Complexity: O(N)
*/

class Box{
    public:
    bool BST;
    int size;
    int min,max;
    
    Box(int data){
        BST=1;
        size=1;
        min=data;
        max=data;
    }
    
};

  Box* find(Node* root,int& TotalSize){
      // Leaf Node 
      if(!root->left && !root->right){
          TotalSize=max(TotalSize,1);
          return new Box(root->data);
      }
      // Only right side exist
      else if(!root->left && root->right){
          Box* head=find(root->right,TotalSize);
    // BST yes
      if(head->BST && head->min > root->data){
          head->size++;
          head->min=root->data;
          TotalSize=max(TotalSize,head->size);
          return head;
      }
    // No
      else{
          head->BST=0;
          return head;
        }
      }
    // Only right side exist
    else if(root->left && !root->right){
        Box* head = find(root->left,TotalSize);
        // BST yes
         if(head->BST && head->max < root->data){
             head->size++;
             head->max=root->data;
             TotalSize=max(TotalSize,head->size);
             return head;
         }
         else{
             head->BST=0;
             return head;
         }
    }
     // Both side exist
     else{
         Box* lefthead=find(root->left,TotalSize);
         Box* righthead=find(root->right,TotalSize);
         
         if(lefthead->BST && righthead->BST && lefthead->max<root->data && righthead->min>root->data){
             Box* head=new Box(root->data);
             head->size+=lefthead->size+righthead->size;
             head->min=lefthead->min;
             head->max=righthead->max;
             TotalSize=max(TotalSize,head->size);
             return head;
         }
         else{
             lefthead->BST=0;
             return lefthead;
         }
     }
      
  }


class Solution{
    public:

    int largestBst(Node *root)
    {
      int TotalSize=0;
      find(root,TotalSize);
      return TotalSize;
    }
};
