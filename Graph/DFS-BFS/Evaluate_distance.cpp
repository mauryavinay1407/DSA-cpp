// problem:  https://leetcode.com/problems/evaluate-division/

/*
Time Complexity: O(E+Q×(V+E))  
Space Complexity: O(V+E+Q)
                       where E is the number of equations (edges).
                             V is the number of variables (nodes).
                             Q is the number of queries.
*/

class Solution {
public:
    vector<double> result;
    void dfs(unordered_map<string,vector<pair<string,double>>>& adj,string src,string dest,unordered_set<string>& visited,double product,double &ans){
      if(visited.count(src))
      return;
      visited.insert(src);
      if(src==dest){
        ans=product;
        return;
      }

      for(auto & node : adj[src]){
      string v=node.first;
      double val=node.second;
      dfs(adj,v,dest,visited,val*product,ans);
      }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string,vector<pair<string,double>>> adj;

    for(int i=0;i<equations.size();i++){
        string u=equations[i][0];
        string v=equations[i][1];
        double val=values[i];
        adj[u].push_back({v, val});
        adj[v].push_back({u, 1.0 / val});
    }
     for(auto& quer:queries){
        string src=quer[0];
        string dest=quer[1];
        double ans=-1.0;
        int product=1;
        unordered_set<string> visited;
        if(adj.find(src)!=adj.end()){
        dfs(adj,src,dest,visited,product,ans);
        }
        result.push_back(ans);
     }
     return result;
    }
};
