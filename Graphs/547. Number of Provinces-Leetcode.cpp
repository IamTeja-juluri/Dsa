//Soln 1 -Converting into adjacency list
class Solution {
public:
    
    
    void dfs(int node,vector<int> adj[],vector<bool>&visited){
        
        visited[node]=true;
        
        for(auto nbr:adj[node]){
            
            if(visited[nbr]==false){
                dfs(nbr,adj,visited);
            }
            
        }
        
        return ;
        
    }
    
    
    int findCircleNum(vector<vector<int>>& grid) {
         
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        vector<int> adj[n];
        vector<bool> visited(n,false);
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if ( (i!=j) && grid[i][j]==1 ){
                     adj[i].push_back(j);
                 }
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans+=1;
               dfs(i,adj,visited);    
            }     
        }
        
        return ans;
        
    }
};
//Soln 2-Without converting into adjacency list
class Solution {
public:
    
    void dfs(int x,int y,vector<vector<int> > &grid){
       
        grid[x][y]=0;
        
        vector<int> v=grid[x];
        
        for(int j=0;j<v.size();j++){
            
            if(grid[x][j]==1){
                 grid[x][j]=0;
                dfs(j,x,grid);
            }
            
        }
        
     return;
        
    }
    
    
    int findCircleNum(vector<vector<int>>& grid) {
         
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if ( grid[i][j]==1 ){
                     ans+=1;
                     dfs(i,j,grid);
                 }
            }
        }
        
       
        
        return ans;
        
    }
};
//soln using dsu
class Graph{
  
    int v;
    int *parent;
    int *rank;
    
    public:
    
    Graph(int v){
        
        this->v=v;
        parent=new int[v];
        rank=new int[v];
        
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        
    }
    
    int findset(int i){
        
        if(parent[i]==-1){
            return i;
        }
        
        return parent[i]=findset(parent[i]);
    }
    
    int provinces(vector<vector<int> > &grid){
        
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(i!=j && grid[i][j]==1){
                    
                    grid[j][i]=0;
                    
                    int s1=findset(i);
                    int s2=findset(j);
                    
                    if(s1!=s2){
                        
                        if(rank[s1]<rank[s2]){
                            rank[s2]+=rank[s1];
                            parent[s1]=s2;
                        }
                        else{
                            rank[s1]+=rank[s2];
                            parent[s2]=s1;
                        }
                        
                    }
                    
                    
                }
                
            }
            
        }
        
        
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                count+=1;
            }
        }
        
        
        return count;
    }
    

};


class Solution {
public:
    
    
    
    int findCircleNum(vector<vector<int>>& grid) {
        
        int n=grid.size();
         
        Graph g(n);
        
        return g.provinces(grid);
        
    }
};