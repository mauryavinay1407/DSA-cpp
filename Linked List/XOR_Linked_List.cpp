// problem:  https://www.geeksforgeeks.org/problems/xor-linked-list/1


struct Node *insert(struct Node *head, int data) {
    Node* newNode=new Node(data);
    newNode->npx=head;
    if(head)
    head->npx=XOR(newNode,head->npx);
    
    return newNode;
}

vector<int> getList(struct Node *head) {
    vector<int> result;
    Node* cur=head;
    Node* pre=NULL;
    Node* next;
    while(cur){
        result.push_back(cur->data);
        next=XOR(cur->npx,pre);
        pre=cur;
        cur=next;
    }
    return result;
}
