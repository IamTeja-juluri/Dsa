//using dfs
class Solution {
public:
    
    vector<vector<int> > adj;
    vector<vector<bool> > reachable;
    vector<bool>visited;
    
    void topo_dfs(int node){
        
        visited[node]=true;
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                reachable[node][nbr]=true;
                topo_dfs(nbr);
            }
        }
        visited[node]=false;
        
    }
    
  
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        
        vector<bool>ans;
        visited.resize(n,false);
        reachable.resize(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
            adj.push_back({});
        
        for(auto x:pre)
            adj[x[0]].push_back(x[1]);
        
        for(int i=0;i<n;i++){
            if(!visited[i])
                topo_dfs(i);
        }
     
        for(auto x:queries){
            if(reachable[x[0]][x[1]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        
        
        return ans;
    }
};
