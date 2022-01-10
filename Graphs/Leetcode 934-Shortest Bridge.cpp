class Solution {
public:
    
    void dfs(int x,int y,vector<vector<bool> >&visited,vector<vector<int> > &grid){
    
    visited[x][y]=true;
    grid[x][y]=2;
  
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    
    int n=grid.size();
    int m=grid[0].size();
    
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && (!visited[newx][newy]) && grid[newx][newy]==1){
            dfs(newx,newy,visited,grid);
        }
    }
    
}
    
    int shortestBridge(vector<vector<int>>& grid) {
        
    
    vector<vector<bool> > visited;
        
    int n=grid.size();
    int m=grid[0].size();
    
    
    for(int i=0;i<n;i++){
       
        vector<bool> v;
        
        for(int j=0;j<m;j++){
            v.push_back(false);
        }
        
        visited.push_back(v);
        
    }
    
    int f=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( (!visited[i][j]) && (grid[i][j]==1) ){
                dfs(i,j,visited,grid);
                f=1;
                break;
            }
        }
        if(f==1)
        break;
    }
    
    int nf=INT_MAX;
        
    vector<pair<int,int> > v;
    vector<pair<int,int> > aux;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                aux.push_back({i,j});
            }
            else if(grid[i][j]==2){
                v.push_back({i,j});
            }
        }
    }
    
    for(int i=0;i<aux.size();i++){
        for(int j=0;j<v.size();j++){
            int x1=aux[i].first;
            int y1=aux[i].second;
            int x2=v[j].first;
            int y2=v[j].second;
            int d=abs(x1-x2)+abs(y1-y2);
            nf=min(nf,d);
        }
    }
    
    return (nf-1);
        
    }
};
