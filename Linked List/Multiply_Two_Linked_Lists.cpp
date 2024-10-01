// problem:  https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

/*
Time Complexity: O(max(n,m))
Space Complexity: O(1)
where n is the size of L1 and m is the size of L2
*/

class solution {
  public:
    int M=1000000007;
    long long multiplyTwoLists(Node *first, Node *second) {
       long long num1=0,num2=0;
        Node* temp=first;
        while(temp){
         num1=(num1*10+temp->data)%M;
          temp=temp->next;
        }
        temp=second;
        while(temp){
            num2=(num2*10+temp->data)%M;
            temp=temp->next;
        }
       
       return (num1*num2)%M; 
    }
};
