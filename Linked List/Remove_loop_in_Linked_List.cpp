// problem :  https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

/*
Approach-1 : Using Floyd's Tortoise and Hare algorithm to detect the cycle and removing the loop (noob way)
Time Complexity   : O(N)
Space Complexity  : O(1)
*/
class Solution {
public:
    void removeLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(!slow || !fast || !fast->next)
            return;
        slow = head;
        Node* temp = NULL;
        while(slow != fast){
            temp = fast;
            slow = slow->next;
            fast = fast->next;
        }
        if(temp){
            temp->next = NULL;
            return;
        }
        do{
            temp = fast;
            fast = fast->next;
        }while(slow != fast);
        temp->next = NULL;
    }
};
/*
Approach-2 : Same as above but a bit clean code
Time Complexity   : O(N)
Space Complexity  : O(1)
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        // detecting the loop existence
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        // no loop is present
        if(!slow || !fast || !fast->next)
            return;
        // finding the first node of loop
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
       // find the last node of loop
       while(fast->next != slow)
            fast = fast->next;
        // removing the loop
        fast->next = NULL;
    }
};
