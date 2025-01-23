// problem: https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

/*
Approach-1: Brute force by checking each node of first with each element of second  (TLE)
Time Complexity:  O(M*N)
Space Complexity   O(1)
*/
class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        Node* temp1=head1;
        while(temp1){
            Node* temp2 = head2;
            while(temp2){
                if(temp2 == temp1)
                    return temp2->data;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return -1;
    }
};
/*
Approach-2: Optimal solution by keep reating the shorter list untill finding the intersection node or both list exhausted
Time Complexity:  O(M + N)
Space Complexity   O(1)
*/
class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        Node* temp1=head1;
        Node* temp2 = head2;
        while(temp1 != temp2){
            temp1 = temp1 ? temp1 -> next : head1;
            temp2 = temp2 ? temp2 -> next : head2;
        }
        return temp1==temp2 ? temp1->data : -1 ;
    }
};

/*
Approach-3: Optimal solution by reducing the length of longer list to same as shorter then comparing and finding the intersection
Time Complexity:  O(M + N)
Space Complexity   O(1)
*/
class Solution {
public:
Node* intersectPoint(Node* head1, Node* head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        int n1 = 0, n2 = 0;
        while (temp1) {
            n1++;
            temp1 = temp1->next;
        }
        while (temp2) {
            n2++;
            temp2 = temp2->next;
        }
        temp1 = head1, temp2 = head2;
        if (n1 > n2) {
            int k = n1 - n2;
            while (k--)
                temp1 = temp1->next;
        } else if (n2 > n1) {
            int k = n2 - n1;
            while (k--)
                temp2 = temp2->next;
        }
        while (temp1 && temp2) {
            if (temp1 == temp2)
                return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};
