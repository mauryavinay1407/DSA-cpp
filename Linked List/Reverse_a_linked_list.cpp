// problem : https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

/*
Approach: using 3 pointers
Time Complexity  :  O(N)
Space Complexity :  O(1)
*/
class Solution {
public:
    Node* reverseList(struct Node* head) {
        Node* pre = NULL;
        Node* cur = head;
        Node* nxt = head;
        while(cur){
            nxt = nxt -> next;
            cur->next = pre;
            pre= cur;
            cur = nxt;
        }
        return pre;
    }
};
