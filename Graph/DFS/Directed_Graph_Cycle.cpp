// problem :  https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/

class Solution {
  public:
 
    bool isCyclic(vector<int> adj[],int u,vector<bool>& visited,vector<bool>& inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        
        for(auto & v:adj[u]){
         if(visited[v] && inRecursion[v])
          return true;
          else if(!visited[v] && isCyclic(adj,v,visited,inRecursion))
             return true;
        }
        inRecursion[u]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V,false);
    vector<bool> inRecursion(V,false);
     for(int i=0;i<V;i++){
         if(!visited[i] && isCyclic(adj,i,visited,inRecursion))
           return true;
     }
     return false;
    }
};
