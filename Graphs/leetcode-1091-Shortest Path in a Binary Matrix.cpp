//Bfs
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
    int n=grid.size();
    int m=grid[0].size();
        
     if(grid[0][0]==1 || grid[n-1][m-1]==1){
        return -1;
    }
    
    queue<pair<int,int > > q;
    q.push({0,0});
    
    int dx[]={1,-1,0,0,-1,-1,1,1};
    int dy[]={0,0,1,-1,-1,1,-1,1};
    
    grid[0][0]=1;
    
    while(!q.empty()){
        
        int x=q.front().first;
        int y=q.front().second;
        
        for(int i=0;i<8;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==0){
                q.push({newx,newy});
                grid[newx][newy]=grid[x][y]+1;
            }
            
        }
        
        q.pop();
    }
        
        if(grid[n-1][m-1]==0){
            return -1;
        }
        
        return grid[n-1][m-1];
        
    }
};
