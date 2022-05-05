class Solution {
public:
    
    
    void markdfs(vector<vector<int>> &grid,int x,int y,int n,int m){
        
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==0)
            return;
        
        grid[x][y]=0;
      
        markdfs(grid,x-1,y,n,m);
        markdfs(grid,x,y+1,n,m);
        markdfs(grid,x,y-1,n,m);
        markdfs(grid,x+1,y,n,m);
        
    }
    
     void dfs(vector<vector<int>> &grid,int x,int y,int n,int m){
        
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==0 || grid[x][y]==2)
            return;
        
        grid[x][y]=2;
      
        dfs(grid,x-1,y,n,m);
        dfs(grid,x,y+1,n,m);
        dfs(grid,x,y-1,n,m);
        dfs(grid,x+1,y,n,m);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
            markdfs(grid,i,0,n,m);
            if(grid[i][m-1]==1)
            markdfs(grid,i,m-1,n,m);
        }
        
         for(int i=0;i<m;i++){
            if(grid[0][i]==1)
            markdfs(grid,0,i,n,m);
            if(grid[n-1][i]==1)
            markdfs(grid,n-1,i,n,m);
        }
        
        int cnt=0;
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    dfs(grid,i,j,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    cnt+=1;
            }
        }
        
        return cnt;
    }
};
