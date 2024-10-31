// problem:  https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1

/*
Approach: Simple traversal and insert
Time: O(N)
Space: O(1)
*/
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) 
   {        
        Node* newNode=getNode(x);
        if (!head) 
            return newNode;
    
        if(x <= head->data){
            newNode->next=head;
            head->prev=newNode;
            return newNode;
        }
        
        Node* temp=head;
        Node* pre = nullptr;

        while(temp){
            if(temp->data > x)
                break;
            pre = temp;
            temp = temp->next;
        }
        
        if(!temp){
            newNode->prev = pre;
            pre->next=newNode;
            
        }
        else{
            newNode->prev = pre;
            newNode->next = temp;
            pre->next=newNode;
            temp->prev=newNode;
        }
        
        return head;    
    }
};
