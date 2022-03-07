class Solution {
public:
     
    int dx[4],dy[4];
    vector<vector<bool>>visited;
    
    Solution(){
        
        dx[0]=1;
        dx[1]=-1;
        dx[2]=0;
        dx[3]=0;
        dy[0]=0;
        dy[1]=0;
        dy[2]=1;
        dy[3]=-1;
        
    }
    
    
     int dfs(int x,int y,int &n,int &m,vector<vector<int>>&grid){
         
         visited[x][y]=true;
         int cost=grid[x][y];
         int ans=0;
         
         for(int i=0;i<4;i++){
             int newx=x+dx[i];
             int newy=y+dy[i];
             if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]!=0 && visited[newx][newy]==false){
                 int subprob=dfs(newx,newy,n,m,grid);
                 ans=max(ans,subprob);
             }
         }
         
         visited[x][y]=false; 
         return cost+ans;   
     }
    
    
      int getMaximumGold(vector<vector<int>>& grid) {
          
       int n=grid.size();
       int m=grid[0].size();
          
       int res=0;
       visited.resize(n,vector<bool>(m,false));
          
            for(int i=0;i<n;i++)
         	  for(int j=0;j<m;j++)
      		     if(grid[i][j])
                     res=max(res,dfs(i,j,n,m,grid)); 
          
             return res;
    }
};
