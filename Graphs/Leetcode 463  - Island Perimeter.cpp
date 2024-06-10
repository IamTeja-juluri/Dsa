# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int count = 0;
        int n= grid.size();
        int m = grid[0].size();

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                        if( (i-1 == -1) || grid[i-1][j] == 0){
                            count+=1;
                        }
                        if( (j+1 == m) || grid[i][j+1] == 0){
                            count+=1;     
                        }
                        if( (i+1 == n) || grid[i+1][j] == 0){
                            count+=1;     
                        }
                        if( (j-1 == -1) || grid[i][j-1] == 0){
                            count+=1;     
                        }
                    }
                }
            }
    
        return count;
    }
};
```
