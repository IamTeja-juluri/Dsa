// This quesn can also be solved in another way.If we carefully observe it is clear that if a connected component of a graph/graph contains 
// cycle and if it contains even no of nodes den it is Bipartite else it is not.
// So use cycle detection and count size of connected component
// Or Using Dsu keep track of rank of evry connected component




class Solution {
public:
    
    bool dfs(int node,int par,int col,vector<int> &color,vector<int> gr[]){
        
        color[node]=col;
        
        for(auto nbr:gr[node]){
            
            if(!color[nbr]){
                bool nbrfound=dfs(nbr,node,3-col,color,gr);
                if(!nbrfound){
                    return false;
                }
            }
            else if(nbr!=par && col==color[nbr]){
                return false;
            }
        }
        return true;
        
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> gr[105];
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++){
            
            vector<int> v=graph[i];
            
            for(int j=0;j<v.size();j++){
                int x=v[j];
                gr[i].push_back(x);
            }
            
        }
          
        for(int i=0;i<n;i++){
            if(color[i]==0){
                bool ans=dfs(i,-1,1,color,gr);
                if(ans==false){
                    return false;
                }
            }
        }
        
        return true;
        
        
    }
};






















