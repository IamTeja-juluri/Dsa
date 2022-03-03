
class Solution {
public:
    
    int tme;
    vector<int > gr[100005];
    vector<bool> visited;
    vector<vector<int> > bridges;
    vector<int> disc,low;
    
        
    void dfs(int node,int par){
        
        visited[node]=true;
        low[node]=disc[node]=tme++;
        
        for(auto nbr:gr[node]){
            
            if(!visited[nbr]){
                dfs(nbr,node);
                
                low[node]=min(low[node],low[nbr]);
                
                if(low[nbr]>disc[node]){
                    vector<int> v;
                    v.push_back(node);
                    v.push_back(nbr);
                    bridges.push_back(v);
                }
                
            }
            else if(nbr!=par){
                low[node]=min(low[node],disc[nbr]);
            }
            
        }
        
        return ;
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         
        
        int m=connections.size();
        
        for(int i=0;i<m;i++){
            
            int x=connections[i][0];
            int y=connections[i][1];
            
            gr[x].push_back(y);
            gr[y].push_back(x);
            
        }
        
        tme=0;
        
        for(int i=0;i<n;i++){
          
            visited.push_back(false);
            disc.push_back(0);
            low.push_back(0);
            
         }
        
        
       for(int i=0;i<n;i++){
           
           if(!visited[i]){
               dfs(i,-1);
           }
           
       }
       
        return bridges;
    }
};