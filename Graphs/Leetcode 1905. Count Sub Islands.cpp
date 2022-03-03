//Unfortunately accepted soln 
//Better refer soln 2 below
class Solution {
public:
    void dfs(int x,int y,vector<vector<int> >&grid1,vector<vector<int>>&grid2,vector<vector<bool> >&visited,int &ans){
        
        int n=grid1.size();
        int m=grid1[0].size();
        
        visited[x][y]=true;
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==false  && grid2[newx][newy]==1){
                
                if(grid1[newx][newy]==grid2[newx][newy]){
                    
                  dfs(newx,newy,grid1,grid2,visited,ans);
                    
                }
                else{
                    
                    ans=0;
                    
                }
                
            }
            
               
        }
          
       return ;  
        
    }
    
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
         int n=grid1.size();
         int m=grid1[0].size();
        
         int count=0;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ans=1;
                if(!visited[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    dfs(i,j,grid1,grid2,visited,ans);
                    if(ans==1){
                        count+=1;
                    }
                }
                
            }
        }
        
      return count;  
        
    }
};

//Soln 2
class Solution {
public:
    void dfs(int x,int y,vector<vector<int> >&grid1,vector<vector<int>>&grid2,vector<vector<bool> >&visited,int &ans){
        
        int n=grid1.size();
        int m=grid1[0].size();
        
        visited[x][y]=true;
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==false  && grid2[newx][newy]==1){
                
                if(grid1[newx][newy]!=grid2[newx][newy]){
                      ans=0;
                }
                
                dfs(newx,newy,grid1,grid2,visited,ans);
                
            }
            
               
        }
          
       return ;  
        
    }
    
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
         int n=grid1.size();
         int m=grid1[0].size();
        
         int count=0;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ans=1;
                if(!visited[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    dfs(i,j,grid1,grid2,visited,ans);
                    if(ans==1){
                        count+=1;
                    }
                }
                
            }
        }
        
      return count;  
        
    }
};