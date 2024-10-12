// problem :  https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

/*
Approach-1: using DFS
Time Complexity: (O(V + E))
Space Complexity: (O(V))
*/
class Solution {
  public:
    bool isCyclic(vector<int> adj[],int u,int parent,vector<bool>& visited){
        visited[u]=true;
        
        for(auto& v:adj[u]){
            if(v!=parent && visited[v])
            return true;
            else if(!visited[v] && isCyclic(adj,v,u,visited))
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<bool> visited(V,false);
       for(int i=0;i<visited.size();i++){
           if(!visited[i] && isCyclic(adj,i,-1,visited))
            return true;
       }
       return false;
    }
};

/*
Approach-2: using BFS
Time Complexity: (O(V + E))
Space Complexity: (O(V))
*/

class Solution {
  public:
     bool cyclicBFS(vector<int> adj[],int i,vector<bool>& visited){
      queue<pair<int,int>> q;
      q.push({i,-1});
      visited[i]=true;
      
      while(!q.empty()){
          int u=q.front().first;
          int parent=q.front().second;
          q.pop();
         
          for(auto& v:adj[u]){
           if(!visited[v]){
           visited[v]=true;
            q.push({v,u});
           }
           else if(v != parent)
            return true;
          }
      }
      
      return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
      vector<bool> visited(V,false);
      
      for(int i=0;i<V;i++){
          if(!visited[i] && cyclicBFS(adj,i,visited))
          return true;
      }
      return false;
    }
};
