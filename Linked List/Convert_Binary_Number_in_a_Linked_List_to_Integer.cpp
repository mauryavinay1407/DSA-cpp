// problem : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

/*
Approach - Using simple traversal
Time Complexity       :   O(N)
Space Complexity      :   O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        n--;
        temp = head;
        int result = 0;
        while (temp) {
            if (temp->val) {
                result += (1 << n);
            }
            n--;
            temp = temp->next;
        }
        return result;
    }
};
