class Solution {
public:
    
    vector<vector<bool>> visited;
    bool dfs(int x,int y,int n,int m,vector<vector<int> > &grid){
        
        if(x==n-1 && y==m-1)
            return true;
        
        if(visited[x][y])
            return false;
        
        visited[x][y]=true;
        
        if(grid[x][y]==1){
            
            bool op1=false,op2=false;
            
            if(y+1<m)
                if(grid[x][y+1]==3 || grid[x][y+1]==5 || grid[x][y+1]==1)
                    op1=dfs(x,y+1,n,m,grid);
            
            if(y-1>=0)
                if(grid[x][y-1]==4 || grid[x][y-1]==6 || grid[x][y-1]==1)
                    op2=dfs(x,y-1,n,m,grid);
            
            return op1||op2;
        }
        
        else if(grid[x][y]==2){
            
             bool op1=false,op2=false;
            
             if(x-1>=0)
                 if(grid[x-1][y]==3 || grid[x-1][y]==4 || grid[x-1][y]==2)
                     op1=dfs(x-1,y,n,m,grid);
            
             if(x+1<n)
                 if(grid[x+1][y]==5 || grid[x+1][y]==6 || grid[x+1][y]==2)
                     op2=dfs(x+1,y,n,m,grid);
            
            return op1||op2;
        }
        
        else if(grid[x][y]==3){
            
            bool op1=false,op2=false;
            
            if(x+1<n)
                if(grid[x+1][y]==5 || grid[x+1][y]==6 || grid[x+1][y]==2)
                    op1=dfs(x+1,y,n,m,grid);
                
            if(y-1>=0)
                if(grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6)
                    op2=dfs(x,y-1,n,m,grid);
                
            return op1||op2;
        }
        
        else if(grid[x][y]==4){
            
             bool op1=false,op2=false;
            
             if(y+1<m)
                 if(grid[x][y+1]==3 || grid[x][y+1]==5 || grid[x][y+1]==1)
                     op1=dfs(x,y+1,n,m,grid);
                 
             if(x+1<n)
                 if(grid[x+1][y]==2 || grid[x+1][y]==5  || grid[x+1][y]==6)
                     op2=dfs(x+1,y,n,m,grid);
            
            return op1||op2;
        }
        
        else if(grid[x][y]==5){
            
            bool op1=false,op2=false;
            
            if(x-1>=0)
                if(grid[x-1][y]==3 || grid[x-1][y]==4 || grid[x-1][y]==2)
                    op1=dfs(x-1,y,n,m,grid);
            if(y-1>=0)
                if(grid[x][y-1]==6 || grid[x][y-1]==4 || grid[x][y-1]==1)
                    op2=dfs(x,y-1,n,m,grid);
            
             return op1||op2;
        }
        
        else {
              bool op1=false,op2=false;
            
             if(x-1>=0)
                 if(grid[x-1][y]==4 || grid[x-1][y]==3 || grid[x-1][y]==2)
                     op1=dfs(x-1,y,n,m,grid);
            
             if(y+1<m)
                 if(grid[x][y+1]==5 || grid[x][y+1]==1 || grid[x][y+1]==3)
                     op2=dfs(x,y+1,n,m,grid);
            
             return op1||op2;
        }
        
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        return dfs(0,0,n,m,grid);
    }
};
