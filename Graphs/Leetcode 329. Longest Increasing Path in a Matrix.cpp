class Solution {
public:
    
    vector<vector<int>>dp;
    int dx[4],dy[4];
    
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
   
    
    int allPaths(int x,int y,vector<vector<int>>&grid){
       
       if(dp[x][y]!=-1)
           return dp[x][y];
        
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m  && grid[newx][newy]>grid[x][y]){
                ans=max(ans,1+allPaths(newx,newy,grid));
            }   
        }
        
        return dp[x][y]=ans;
        
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        dp.resize(n,vector<int>(m,-1));
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,1+allPaths(i,j,mat));
            }
        }
        
        return ans;
    }
};
