// problem: https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1

/*
Approach: Using mean heap 
Time Complexity: O(N*logk)
Space Compplexity: O(k)
*/

class Solution {
  public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        DLLNode* curr = head;
        for(int i=0;curr && i<=k;i++){
                pq.push(curr->data);
                curr=curr->next;
        }
        DLLNode* newHead = head;
        while(!pq.empty()){
            newHead->data=pq.top();
            pq.pop();
            newHead=newHead->next;
            if(curr){
                pq.push(curr->data);
                curr=curr->next;
            }
        }
        return head;
    }
};
