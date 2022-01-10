class Solution {
public:
    
    void dfs(int x,int y,vector<vector<bool> >&visited,vector<vector<int> > &grid){
    
    visited[x][y]=true;
   
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    
    int n=grid.size();
    int m=grid[0].size();
    
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && (!visited[newx][newy]) && grid[newx][newy]==0){
            dfs(newx,newy,visited,grid);
        }
    }
    
}


void mark(int x,int y,vector<vector<bool> >&visited,vector<vector<int> > &grid){
    
    visited[x][y]=true;
   
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    
    grid[x][y]=2;
    
    int n=grid.size();
    int m=grid[0].size();
    
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && (!visited[newx][newy]) && grid[newx][newy]==0){
            mark(newx,newy,visited,grid);
        }
    }
    
}

    
    int closedIsland(vector<vector<int>>& grid) {
        
    vector<vector<bool> > visited;
 
    int n=grid.size();
    int m=grid[0].size();
    
    for(int i=0;i<n;i++){
       
        vector<bool>r;
        
        for(int j=0;j<m;j++){
           
            r.push_back(false);
        }
        
        visited.push_back(r);
    }
    
    
    for(int i=0;i<m;i++){
        
        if( (!visited[0][i]) && (grid[0][i]==0) ){
            mark(0,i,visited,grid);
        }
        
        if( (!visited[n-1][i]) && (grid[n-1][i]==0) ){
            mark(n-1,i,visited,grid);
        }
    }
    
    for(int i=0;i<n;i++){
        
        if( (!visited[i][0]) && (grid[i][0]==0) ){
            mark(i,0,visited,grid);
        }
        
        if( (!visited[i][m-1]) && (grid[i][m-1]==0) ){
            mark(i,m-1,visited,grid);
        }
    }
    
    int count=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( (!visited[i][j]) && (grid[i][j]==0) ){
                dfs(i,j,visited,grid);
                count+=1;
            }
        }
    }
    
   return count;
        
        
    }
};
