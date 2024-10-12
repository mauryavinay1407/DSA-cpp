// problem: https://www.geeksforgeeks.org/problems/topological-sort/1

/*
Approach-1: Using DFS
Time Complexiy: O(V + E)
Space Complexiy: O(V)
*/

class Solution
{
	public:
	void tSortDFS(vector<int> adj[],int u,vector<bool>& visited,stack<int>& st){
	    visited[u]=true;
	    for(auto& v : adj[u]){
	        if(!visited[v])
	        tSortDFS(adj,v,visited,st);
	    }
	    st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<bool> visited(V,false);
	   stack<int> st;
	   vector<int> result;
	   for(int i=0;i<V;i++){
	       if(!visited[i])
	       tSortDFS(adj,i,visited,st);
	   }
	   while(!st.empty()){
	       result.push_back(st.top());
	       st.pop();
	   }
	   return result;
	}
};

/*
Approach-2: Using BFS (Kahn's Algorithm)
Time Complexiy: O(V + E)
Space Complexiy: O(V)
*/

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   queue<int> q;
	   vector<int> indegree(V,0);
	   vector<int> result;
    
	   // First store the indegree of vertices
	    for(int i=0;i<V;i++)
	       for(auto& v : adj[i])
	          indegree[v]++;
    
	   // push the vertices into queue and result which have 0 indegree 
	   for(int i=0;i<V;i++){
	    if(indegree[i]==0){
	      q.push(i);
	      result.push_back(i);
	    }
	   }
	 // keep decreasing the indegree of vertices and do same as above which become 0  
	   while(!q.empty()){
	     int u=q.front();
	     q.pop();
	     for(auto& v:adj[u]){
	      indegree[v]--;
	      if(indegree[v]==0){
	      q.push(v);
	       result.push_back(v);
	      }
	     }
	   }   
	   return result;
	}
};
