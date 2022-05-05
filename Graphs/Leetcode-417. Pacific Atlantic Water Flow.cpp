class Solution {
public:
    
    vector<vector<int> > mark;
    int n,m;
    
//     void dfs(vector<vector<int>>&grid,vector<vector<int> > &mark,int x,int y,int n,int m,int prev){
      
  
//        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]>prev || mark[x][y]==1)
//             return;
        
//         mark[x][y]=1;
//         dfs(grid,mark,x+1,y,n,m,grid[x][y]);
//         dfs(grid,mark,x-1,y,n,m,grid[x][y]);
//         dfs(ggridk,x,y+1,n,m,grid[x][y]);
//         dfs(grid,mark,x,y-1,n,m,grid[x][y]);
        
        
//     }
    
 void dfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int i, int j) {
    
    vis[i][j] = true; 
 
    if(i+1 < n && !vis[i+1][j] && grid[i+1][j] >= grid[i][j]) {
        dfs(grid, vis, i+1, j);  //Down
    }
    if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] >= grid[i][j]) {
        dfs(grid, vis, i-1, j);  //Up
    }
    if(j+1 < m && !vis[i][j+1] && grid[i][j+1] >= grid[i][j]) {
        dfs(grid, vis, i, j+1);  //Right
    }
    if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] >= grid[i][j]) {
        dfs(grid, vis, i, j-1);  //Left
    }
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
