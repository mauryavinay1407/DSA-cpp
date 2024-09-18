// problem :  https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

/*
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
