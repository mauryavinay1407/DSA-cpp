// problem:  https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

/*
Approach:  Allmost same as typical quick sort
Time Complexity:    O(N*logN)
Space Complexity:   O(logN)  due to recursion
*/

class Solution {
  public:
        Node* partition(Node* head,Node* tail){
        Node* temp=head->next,*prev=head,*key=head;
        while(temp!=tail->next){
            if(key->data > temp->data){
                swap(prev->next->data,temp->data);
                prev=prev->next;
            }
            temp=temp->next;
        }
        swap(key->data, prev->data);
        return prev;
    }
    void QuickSort(Node* head,Node* tail){
        if(head && head!=tail){
            Node* p=partition(head,tail);
            QuickSort(head,p);
            QuickSort(p->next,tail);
        }
    }
    struct Node* quickSort(struct Node* head) {
        if(!head->next)
            return head;
        Node* tail=head;
        while(tail->next)
            tail=tail->next;
        QuickSort(head,tail);
        return head;
    }
};
