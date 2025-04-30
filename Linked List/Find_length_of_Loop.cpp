// problem  :  https://www.geeksforgeeks.org/problems/find-length-of-loop/1

/*
Approach - Using Floyd Cycle Detection
Time Complexity     :  O(N)
Space Complexity    :  O(1)
*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        int result = 0;
        Node* slow = head;
        Node* fast = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(!slow || !fast || !fast->next){
            return 0;
        }
        
        do{
            result++;
            fast = fast->next;
        }while(slow != fast);
        
        return result;
    }
};
