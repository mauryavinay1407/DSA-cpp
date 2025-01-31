// problem : https://leetcode.com/problems/reverse-nodes-in-k-group

/*
Approach-1:  using recursion
Time Complexity   :  O(N) 
Space Complexity  :  O(N/k)
*/
class Solution {
public:
    int getLength(ListNode* temp) {
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int n = getLength(head);
        if (head == NULL)
            return head;

        else if (n < k) {
            return head;
        }

        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* next = head;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        if (next)
            head->next = reverseKGroup(next, k);

        return pre;
    }
};
/*
Approach-2:  iterative
Time Complexity   :  O(N) 
Space Complexity  :  O(1)
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head;
        int length = 0;

        // Count the total length of the linked list
        while (curr) {
            length++;
            curr = curr->next;
        }

        curr = head;
        while (length >= k) {
            ListNode *next = curr->next, *tail = curr;
            ListNode *prevTail = prev;
            
            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prevTail->next;
                prevTail->next = next;
                next = curr->next;
            }

            prev = tail;
            curr = prev->next;
            length -= k;
        }

        return dummy.next;
    }
};
