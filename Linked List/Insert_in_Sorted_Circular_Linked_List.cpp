// problem  : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

/*
Approach - Using simple traversal
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        
         Node* newNode = new Node(data); 
    
        // If linked list is empty
        if (head == nullptr) {
            newNode->next = newNode; 
            head = newNode;
            return head;
        }
        
        Node* curr = head;
        Node* nextToCurr = head->next;
        
        // Insert at the beginning if data is less 
      	// than or equal to head's data
        if (data <= head->data) {
            Node* lastNode = head;
            while (lastNode->next != head) {
              	
              	// Find the last node
                lastNode = lastNode->next; 
            }
          
          	// Set new node's next to head
            newNode->next = head; 
            
          	// Update last node's next to new node
          	lastNode->next = newNode; 
            
          	// Update head to new node
          	head = newNode; 
            return head;
        }
        
        // Insert in the middle of the list
        while (curr->next != head) {
            if (curr->data < data && nextToCurr->data >= data) {
              	
              	// Set new node's next to current's next
                newNode->next = curr->next; 
                curr->next = newNode;
                return head;
            } else {
              
              	// Move to the next node
                curr = curr->next; 
                nextToCurr = nextToCurr->next; 
            }
        }
        
        // Insert at the end of the list
        newNode->next = head; 
        curr->next = newNode; 
        return head;
    }
};
