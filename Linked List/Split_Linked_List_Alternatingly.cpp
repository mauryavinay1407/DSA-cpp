// problem:  https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1

/*
Approach  :    Using simple iteration and pointer
Time Complexity: O(N)
Space Complexity: O(1)
*/

    vector<Node*> alternatingSplitList(struct Node* head) {
    if (!head) return {}; 
    if (!head->next) return {head, nullptr}; 

    Node* left = head;             
    Node* right = head->next;       
    Node* leftCurr = left;          
    Node* rightCurr = right;        

    Node* curr = head->next->next;  
    bool addToLeft = true;          

    while (curr) {
        if (addToLeft) {
            leftCurr->next = curr;  
            leftCurr = leftCurr->next;
        } else {
            rightCurr->next = curr; 
            rightCurr = rightCurr->next;
        }
        addToLeft = !addToLeft;     
        curr = curr->next;          
    }

    leftCurr->next = nullptr;       
    rightCurr->next = nullptr;      

    return {left, right};           
}
