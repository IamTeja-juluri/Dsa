class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[n-1][m-1] || grid[0][0]){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=-1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][0]!=-1){
                grid[i][0]=1;
            }
            else{
                break;
            }
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j]!=-1){
                grid[0][j]=1;
            }
            else{
                break;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==-1){
                    continue;
                }
                else{
                    if(grid[i-1][j]!=-1 && grid[i][j-1]!=-1){
                        grid[i][j]=grid[i-1][j]+grid[i][j-1];
                    }
                    else if(grid[i-1][j]!=-1){
                        grid[i][j]=grid[i-1][j];
                    }
                    else{
                        grid[i][j]=grid[i][j-1];
                    }
                }
            }
        }
        
        if(grid[n-1][m-1]==-1) return 0;
        
        return grid[n-1][m-1];
        
    }
};