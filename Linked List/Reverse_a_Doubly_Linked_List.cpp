// problem : https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

/*
Approach - Iterative approach using pointer manipulation
Time Complexity   :  O(N)
Space Complexity  :  O(1)
*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr=NULL;
        Node* post=head;
        while(post){
            curr=post;
            post=post->next;
            swap(curr->next,curr->prev);
        }
        return curr;
    }
};
