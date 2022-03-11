class Solution {
public:
    
  void dfs(vector<int> adj[],int node,vector<bool>& visited){
        visited[node]=true;
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                dfs(adj,nbr,visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            dfs(adj,i,visited);
            
            for(int j=0;j<n;j++){
                if(visited[j] && i!=j){
                    res[j].push_back(i);
                }
            }
        }
        return res;
    }
    
};
