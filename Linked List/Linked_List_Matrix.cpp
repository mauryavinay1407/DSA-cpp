// problem: https://www.geeksforgeeks.org/problems/linked-list-matrix/1

/*
Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
      int n=mat.size();
      vector<vector<Node*>> LLM(n,vector<Node*>(n,nullptr));
      
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            LLM[i][j]=new Node(mat[i][j]);        
          }
      }
      
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(j+1<n)
              LLM[i][j]->right=LLM[i][j+1];
              if(i+1<n)
              LLM[i][j]->down=LLM[i+1][j];
          }
      }
      return LLM[0][0];
    }
};
