// problem : https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

/*
Approach : reverse the lists and add them using simple addition of 2 lists
Time Complexity    :  O(m + n)
Space Complexity   :  O(m + n)
*/
class Solution {
public:
    Node* addLists(Node* l1, Node* l2, Node* sum, int carry) {
        if (l1 == NULL && l2 == NULL) {
            if (carry) {
                sum->next = new Node(carry);
                sum = sum->next;
            }
            return sum;
        }
        if (l1 != NULL && l2 == NULL) {
            int temp = carry + l1->data;
            carry = temp / 10;
            temp = temp % 10;
            sum->next = new Node(temp);
            sum = sum->next;
            return addLists(l1->next, l2, sum, carry);
        }
        if (l1 == NULL && l2 != NULL) {
            int temp = carry + l2->data;
            carry = temp / 10;
            temp = temp % 10;
            sum->next = new Node(temp);
            sum = sum->next;
            return addLists(l1, l2->next, sum, carry);
        }
        int temp = l1->data + l2->data + carry;
        carry = temp / 10;
        temp = temp % 10;
        sum->next = new Node(temp);
        sum = sum->next;
        return addLists(l1->next, l2->next, sum, carry);
    }
    
    Node* reverseList(Node* num){
        Node* pre = NULL;
        Node* curr = num;
        Node* nxt = num;
        while(curr){
            nxt = nxt->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        
        Node* head = NULL;
        Node* sumHead = new Node(0);
        head = sumHead;
        addLists(num1, num2, sumHead, 0);
        sumHead = head->next;
        head->next = NULL;
        delete head;

        // Return the actual head of the resultant list (skipping dummy)
        sumHead = reverseList(sumHead);
        while(sumHead && sumHead->data == 0)
            sumHead = sumHead->next;
        return sumHead;
    }
};
