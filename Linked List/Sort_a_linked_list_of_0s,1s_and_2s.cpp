// problem  :  https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*
Approach - By counting 0,1 and 2
Time Complexity     :  O(N)
Space Complexity    :  O(1)
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        int zero=0,one=0,two=0;
        Node* temp = head;
        while(temp){
            if(temp->data == 0){
                zero++;
            }
            else if(temp->data == 1){
                one++;
            }
            else{
                two++;
            }
            temp = temp->next;
        }
        temp=head;
        while(zero--){
            temp->data = 0;
            temp = temp->next;
        }
        while(one--){
            temp->data = 1;
            temp = temp->next;
        }
        while(two--){
            temp->data = 2;
            temp = temp->next;
        }
        return head;
    }
};
