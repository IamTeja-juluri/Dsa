class Solution {
public:
    
    void is_island(int i,int j,vector<vector<char>> &grid,int n,int m){
        
        if(i==-1 || i==n || j==-1 || j==m || grid[i][j]!='1'){
            return ;
        }
        
        grid[i][j]='2';
        
        is_island(i+1,j,grid,n,m);
        is_island(i,j+1,grid,n,m);
        is_island(i-1,j,grid,n,m);
        is_island(i,j-1,grid,n,m);
        
        
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        
        if(n==0)
            return 0;
        
        int no_of_islands=0;
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                
                if(grid[i][j]=='1'){
                    no_of_islands+=1;
                    is_island(i,j,grid,n,m);
                }
            }
        }
        
        return no_of_islands;
        
    }
};
