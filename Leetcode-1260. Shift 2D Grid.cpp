class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int> > temp(n,vector<int>(m,0));
        
        int save=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              
                int col=(j+k)%m;
                int row=(i+(j+k)/m)%n;
                
              temp[row][col]=grid[i][j];    
            }
        }
        
        
        return temp;
        
    }
};
