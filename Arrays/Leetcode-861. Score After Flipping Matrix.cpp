class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        //flipping rows to make first column all ones because msb gives max value all the time
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)
               for(int j=0;j<m;j++)
                   grid[i][j]=!grid[i][j];
        }
        
        int count[21]={0};
        
        //counting no of zeros and ones in every column to see if we have to flip starting from first column
        //if more zeros then flip column
        //do it for all columns
        
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]==1)
                    count[j]+=1;
            }
            if(count[j]<(n-count[j])){
                for(int k=0;k<n;k++)
                    grid[k][j]=!grid[k][j];
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int sum=0;
            int c=0;
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==1)
                sum=sum+(1<<c);
                c+=1;
            }
            ans=ans+sum;
        }
        
      
         return ans;  
    }
};
