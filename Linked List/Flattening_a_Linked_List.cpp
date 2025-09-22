// problem : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/*
Approach-1 : Using recursion
Time Complexity    :  O(N*logk)  where N = total no. of nodes and k = no. of linked lists.
Space Complexity   :  O(N)
*/
class Solution {
public:
    Node* mergeSortedList(Node* list1,Node* list2){
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->data <= list2->data){
            list1->bottom = mergeSortedList(list1->bottom,list2);
            return list1;
        }
        else{
            list2->bottom = mergeSortedList(list1,list2->bottom);
            return list2;
          }
    }
    Node *flatten(Node *root) {
        if(!root)
            return root;
        Node* head = flatten(root->next);
        return mergeSortedList(root,head);
    }
};
/*
Approach-2 : Iterative approach
Time Complexity    :  O(N*logk)  where N = total no. of nodes and k = no. of linked lists.
Space Complexity   :  O(1)
*/
class Solution {
public:
    Node* mergeSortedList(Node* list1, Node* list2) {
        Node dummy(0); // Dummy node to simplify handling
        Node* tail = &dummy;

        while (list1 && list2) {
            if (list1->data <= list2->data) {
                tail->bottom = list1;
                list1 = list1->bottom;
            } else {
                tail->bottom = list2;
                list2 = list2->bottom;
            }
            tail = tail->bottom;
        }

        // Attach remaining nodes
        tail->bottom = (list1) ? list1 : list2;

        return dummy.bottom;
    }

    // Function to flatten the linked list
    Node *flatten(Node *root) {
        if (!root) return root;

        Node* head = nullptr;
        while (root) {
            head = mergeSortedList(head, root);
            root = root->next;
        }

        return head;
    }
};
