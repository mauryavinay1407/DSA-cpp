// problem:  https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

/*
Approach:  Using two stacks , where st1 was for traversing Left to Right and st2 for Right to Left.
Time Complexity: O(N)
Space Complexity: O(N)
*/

vector<int> findSpiral(Node *root)
{
    stack<Node*> st1;
    stack<Node*> st2;
    vector<int> result;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            Node* temp=st1.top();
            st1.pop();
            result.push_back(temp->data);
            if(temp->right)
             st2.push(temp->right);
            if(temp->left)
             st2.push(temp->left);
        }
        while(!st2.empty()){
            Node* temp=st2.top();
            st2.pop();
            result.push_back(temp->data);
            if(temp->left)
             st1.push(temp->left);
            if(temp->right)
             st1.push(temp->right);
        }
    }
    return result;
}
