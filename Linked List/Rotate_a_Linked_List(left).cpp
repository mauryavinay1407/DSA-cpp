// problem : https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

/*
Approach : By simple traversing and shifting 
Time Complexity  : O(N)
Space Complexity : O(1)
*/
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (k == 0 || head == NULL)
            return head;
        Node* curr = head;
        int len = 1;
        while (curr->next != NULL) {
            curr = curr->next;
            len += 1;
        }
        k %= len;
        if (k == 0)
            return head;
        curr->next = head;
        curr = head;
        for (int i = 1; i < k; i++)
            curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
