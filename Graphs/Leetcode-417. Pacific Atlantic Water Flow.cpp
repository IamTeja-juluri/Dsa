//app1
class Solution {
public:
    
    vector<vector<int> > mark;
    int n,m;
    
    void dfs(vector<vector<int>>&grid,vector<vector<int> > &mark,int x,int y,int prev){
        
        if(x<0 || x>=n || y<0 || y>=m || mark[x][y]==1 || grid[x][y]<prev )
            return;
         
        mark[x][y]=1;    
        dfs(grid,mark,x+1,y,grid[x][y]);
        dfs(grid,mark,x-1,y,grid[x][y]);
        dfs(grid,mark,x,y+1,grid[x][y]);
        dfs(grid,mark,x,y-1,grid[x][y]);
        
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
         n=grid.size();
         m=grid[0].size();
        
        vector<vector<int> > visited1,visited2;
        
        visited1.resize(n,vector<int>(m,0));
        visited2.resize(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(visited1[i][0]==0)
            dfs(grid,visited1,i,0,-1);
            if(visited2[i][m-1]==0)
            dfs(grid,visited2,i,m-1,-1);
        }
        
        for(int i=0;i<m;i++){
            if(visited1[0][i]==0)
            dfs(grid,visited1,0,i,-1);
            if(visited2[n-1][i]==0)
            dfs(grid,visited2,n-1,i,-1);
        }
        
        
        vector<vector<int> >res;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited1[i][j] && visited2[i][j])
                    res.push_back({i,j});
            }
        }   
           
        
        return res;
    }
};

//app2

class Solution {
public:
    
    vector<vector<int> > mark;
    int n,m;
    
    
 void dfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int i, int j) {
    
    vis[i][j] = true; 
 
    if(i+1 < n && !vis[i+1][j] && grid[i+1][j] >= grid[i][j]) 
        dfs(grid, vis, i+1, j); 
   
    if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] >= grid[i][j]) 
        dfs(grid, vis, i-1, j); 
    
    if(j+1 < m && !vis[i][j+1] && grid[i][j+1] >= grid[i][j])
        dfs(grid, vis, i, j+1);
     
    if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] >= grid[i][j]) 
        dfs(grid, vis, i, j-1); 
}   
    
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
         n=grid.size();
         m=grid[0].size();
        
        vector<vector<int> > visited1,visited2;
        
        visited1.resize(n,vector<int>(m,0));
        visited2.resize(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            dfs(grid,visited1,i,0);
            dfs(grid,visited2,i,m-1);
        }
        
        for(int i=0;i<m;i++){
            dfs(grid,visited1,0,i);
            dfs(grid,visited2,n-1,i);
        }
        
        
        vector<vector<int> >res;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited1[i][j] && visited2[i][j])
                    res.push_back({i,j});
            }
        }   
           
        
        return res;
    }
};
