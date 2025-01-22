// problem : https://leetcode.com/problems/add-two-numbers

/*
Approach: Simple addition by traversing both lists
Time Complexity  :  O(max(m,n))
Space Complexity :  O(1)
*/

class Solution {
public:
    ListNode* final_addTwoNumbers(ListNode* l1, ListNode* l2, ListNode* sum,
                                  int carry) {
        if (l1 == NULL && l2 == NULL) {
            if (carry) {
                sum->next = new ListNode(carry);
                sum = sum->next;
            }
            return sum;
        }
        if (l1 != NULL && l2 == NULL) {
            int temp = carry + l1->val;
            carry = temp / 10;
            temp = temp % 10;
            sum->next = new ListNode(temp);
            sum = sum->next;
            return final_addTwoNumbers(l1->next, l2, sum, carry);
        }
        if (l1 == NULL && l2 != NULL) {
            int temp = carry + l2->val;
            carry = temp / 10;
            temp = temp % 10;
            sum->next = new ListNode(temp);
            sum = sum->next;
            return final_addTwoNumbers(l1, l2->next, sum, carry);
        }
        int temp = l1->val + l2->val + carry;
        carry = temp / 10;
        temp = temp % 10;
        sum->next = new ListNode(temp);
        sum = sum->next;
        return final_addTwoNumbers(l1->next, l2->next, sum, carry);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* sum = new ListNode();
        head = sum;
        final_addTwoNumbers(l1, l2, sum, 0);
        sum = head->next;
        head->next = NULL;
        delete head;
        return sum;
    }
};
