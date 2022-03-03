class Solution {
public:
    
    bool dfs(int node,int par,int col,vector<int> &color,vector<int> gr[]){
        
        color[node]=col;
        
        for(auto nbr:gr[node]){
            
            if(!color[nbr] ){
                bool subprob=dfs(nbr,node,3-col,color,gr);
                if(!subprob) 
                    return false;
            }
            else if( nbr!=par && col==color[nbr]){
                     return false;
            }
        }
        
        return true;
        
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        
        vector<int> color(n,0);
        vector<int> gr[n];
        
        for(int i=0;i<d.size();i++){
              int x=d[i][0]-1;
              int y=d[i][1]-1;
            gr[x].push_back(y);
            gr[y].push_back(x);
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