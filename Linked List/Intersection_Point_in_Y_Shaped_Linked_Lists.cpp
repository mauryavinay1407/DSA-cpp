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
