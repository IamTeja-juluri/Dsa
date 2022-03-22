class Solution {
public:
    
//     int dx[4],dy[4];
    int ans;
    vector<vector<bool>>visited;
    
//     Solution(){
        
//         dx[0]=1;
//         dx[1]=-1;
//         dx[2]=0;
//         dx[3]=0;
        
//         dy[0]=0;
//         dy[1]=0;
//         dy[2]=1;
//         dy[3]=-1;
      
//     }
    
    void backTrack(vector<vector<int>>&grid,int x,int y,int c){
        
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==-1 || visited[x][y]==true ){
         return;   
        }
        
        if(grid[x][y]==2){
            if(c==-1)
               ans+=1;
            return;
        }
        
        visited[x][y]=true;
        
        backTrack(grid,x,y-1,c-1);
        backTrack(grid,x-1,y,c-1);
        backTrack(grid,x,y+1,c-1);
        backTrack(grid,x+1,y,c-1);
        
        visited[x][y]=false;
    
    }
    
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
     
        
        int spx,spy;
        int count0=0;
        ans=0;
        
        visited.resize(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    spx=i;
                    spy=j;
                }
                if(grid[i][j]==0)
                    count0+=1;
            }
        }
        
        backTrack(grid,spx,spy,count0);
        
        return ans;
    }
};
