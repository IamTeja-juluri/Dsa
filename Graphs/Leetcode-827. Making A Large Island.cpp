class Solution {
public:
    
    //give unique ids to all islands
    //store id and islandsize of every island in map
    //check for sizes of neighbouring islands for every zero
    //take max of all
    bool isValid(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        return true;
    }
    
    int dfs(int x,int y,int n,int m,int id,vector<vector<int>>&grid){
        
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==0 || grid[x][y]>1)
            return 0;
        
        grid[x][y]=id;
        
        return 1+dfs(x+1,y,n,m,id,grid)+dfs(x,y-1,n,m,id,grid)+dfs(x-1,y,n,m,id,grid)+dfs(x,y+1,n,m,id,grid);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,int>mp;
        
        int id=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    id+=1;
                    int islandsize=dfs(i,j,n,m,id,grid);
                    mp[id]=islandsize;
                }
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==0){
                    int sum=0;
                    set<int>st;
                    if(isValid(i-1,j,n,m) && grid[i-1][j]>1){
                        if(st.find(grid[i-1][j])==st.end()){
                        st.insert(grid[i-1][j]);
                        sum+=mp[grid[i-1][j]];
                        }
                    }
                    if(isValid(i,j+1,n,m) && grid[i][j+1]>1){
                        if(st.find(grid[i][j+1])==st.end()){
                        st.insert(grid[i][j+1]);
                        sum+=mp[grid[i][j+1]];
                        }
                    }
                    if(isValid(i+1,j,n,m) && grid[i+1][j]>1){
                        if(st.find(grid[i+1][j])==st.end()){
                        st.insert(grid[i+1][j]);
                        sum+=mp[grid[i+1][j]];
                        }
                    }
                    if(isValid(i,j-1,n,m) && grid[i][j-1]>1){
                        if(st.find(grid[i][j-1])==st.end()){
                        st.insert(grid[i][j-1]);
                        sum+=mp[grid[i][j-1]];
                        }
                    }
                    ans=max(ans,sum+1);
                }
                
            }
        }
        
        return ans==INT_MIN?n*m:ans;
    }
};
