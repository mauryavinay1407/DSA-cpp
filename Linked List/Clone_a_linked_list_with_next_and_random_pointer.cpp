// problem:  https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

/* 
Approach-1:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
  public:
    Node *copyList(Node *head) {
        // Write your code here
        Node* newList=new Node(0);
        Node* tail=newList;
        Node* temp=head;
        while(temp->next){
        Node* t=new Node(temp->data);
        t->next=temp->next;
        t->random=temp->random;
        tail->next=t;
        tail=t;
        temp=temp->next;
        }
        return newList->next;
    }
};

/*
Approach-2:
Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    Node* copyList(Node* head) {
        if (!head) return nullptr;

        // Setting the copied node
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // Set the random pointers for the copied nodes
        temp = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next; 
        }

        // disconnect all the duplicate nodes
        Node* newHead = head->next;
        Node* copy = newHead;
        temp = head;

        while (temp) {
            temp->next = temp->next->next;  // Restore original list
            if (copy->next) {
                copy->next = copy->next->next;  // Separate copied list
            }
            temp = temp->next;
            copy = copy->next;
        }

        return newHead;
    }
};
