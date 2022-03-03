class Solution {
public:
    
    bool dfs(int x,int y,int parx,int pary,vector<vector<char> > &grid,vector<vector<bool> > &visited){
        
       int n=grid.size();
       int m=grid[0].size();
        
       visited[x][y]=true;
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m) {
                 
                if(!visited[newx][newy] && grid[newx][newy]==grid[x][y]){
                    bool nbrfound=dfs(newx,newy,x,y,grid,visited);
                    if(nbrfound)
                        return true;
                }
                else if(grid[newx][newy]==grid[x][y] && newx!=parx && newy!=pary){
                    return true;
                }
                
            }
            
        }
        
        return false;
    }
    
    
    
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool> >visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && dfs(i,j,-1,-1,grid,visited)){
                    return true;
                }
            }
        }
        
        return false;
        
        
    }
};