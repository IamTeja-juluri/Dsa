class Solution {
public:
    
    vector<bool>visited,stack,cycle;
    
    bool dfs(int node,vector<int> adj[]){
        
        visited[node]=true;
        stack[node]=true;
        
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                bool nbrfound=dfs(nbr,adj);
                if(nbrfound)
                    return cycle[node]=true;
            }
            else if(stack[nbr]){
                return cycle[node]=true;
            }
        }
        
        stack[node]=false;
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
           
           int n=graph.size();
           vector<int> adj[n];
        
           for(int i=0;i<n;i++){
               for(int j=0;j<graph[i].size();j++)
                   adj[i].push_back(graph[i][j]);
           }
        
           visited.resize(n,false);
           stack.resize(n,false);
           cycle.resize(n,false);
            
           for(int i=0;i<n;i++){
               if(!visited[i])
                 dfs(i,adj);
           }
          
          vector<int> ans;
        
          for(int i=0;i<n;i++){
              if(!cycle[i])
                  ans.push_back(i);
          }
          
        
         return ans;
    }
};
