//  problem : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

/*
T.C : O(3^(n^2))
S.C : O(L * X) - L = Length of path, X = number of paths
*/

class Solution {
  public:
    int m,n;
    vector<string> ans;
    map<vector<int>,char> directions={{{1,0},'D'},{{-1,0},'U'},{{0,1},'R'},{{0,-1},'L'}};
    
    void dfs(vector<vector<int>>& mat,int i,int j,string& Dir){
        if(i==m-1 && j==n-1 && mat[i][j]==1){
            ans.push_back(Dir);
            return;
        }
        if(i<0||j<0||i>=m||j>=n||mat[i][j]==0)
        return;
        
        mat[i][j]=0;
        
        for(auto& dir:directions){
         int new_i=dir.first[0]+i;
         int new_j=dir.first[1]+j;
         if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && mat[new_i][new_j]==1){
             Dir+=dir.second;
             dfs(mat,new_i,new_j,Dir);
             Dir.pop_back();
         }
        }
        mat[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        m=mat.size();
        n=mat[0].size();
        
       if(!mat[0][0])
       return ans;
       
       string Dir="";
       dfs(mat,0,0,Dir);   
       
       return ans;
    }
};
