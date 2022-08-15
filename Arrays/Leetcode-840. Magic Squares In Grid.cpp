class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
       
        
        int cnt=0;
         
        
        for(int i=2;i<grid.size();i++){
            for(int j=2;j<grid[i].size();j++){
                
                int first_row=grid[i-2][j-2]+grid[i-2][j-1]+grid[i-2][j];
                int second_row=grid[i-1][j-2]+grid[i-1][j-1]+grid[i-1][j];
                int third_row=grid[i][j-2]+grid[i][j-1]+grid[i][j];
                
                int first_col=grid[i-2][j-2]+grid[i-1][j-2]+grid[i][j-2];
                int second_col=grid[i-2][j-1]+grid[i-1][j-1]+grid[i][j-1];
                int third_col=grid[i-2][j]+grid[i-1][j]+grid[i][j];
                
                int ld=grid[i-2][j-2]+grid[i-1][j-1]+grid[i][j];
                int rd=grid[i-2][j]+grid[i-1][j-1]+grid[i][j-2];
                
                set<int> s;
                s.insert(first_row);
                s.insert(second_row);
                s.insert(third_row);
                
                s.insert(first_col);
                s.insert(second_col);
                s.insert(third_col);
                
                s.insert(ld);
                s.insert(rd);
                
                set<int> nat{1,2,3,4,5,6,7,8,9};
                
                nat.erase(grid[i-2][j-2]);
                nat.erase(grid[i-2][j-1]);
                nat.erase(grid[i-2][j]);
                
                nat.erase(grid[i-1][j-2]);
                nat.erase(grid[i-1][j-1]);
                nat.erase(grid[i-1][j]);
                
                nat.erase(grid[i][j-2]);
                nat.erase(grid[i][j-1]);
                nat.erase(grid[i][j]);
         
                if(nat.size()==0 and s.size()==1)
                    cnt+=1;
                
            }
        }
        
        return cnt;
    }
};
