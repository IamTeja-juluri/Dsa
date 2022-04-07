class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++)
                v.push_back(grid[i][j]);
        }
        
        sort(v.begin(),v.end());
        
        int n=v.size();
        int median=n/2;
        
        int minOp=0;
        
        for(int i=0;i<n;i++){
            
            if(i==n/2)
                continue;
            
            else if(i<(n/2)){
                if( (v[median]-v[i])%x != 0 )
                    return -1;
                minOp+=(v[median]-v[i])/x;
            }
            else{
                if( (v[i]-v[median])%x != 0)
                    return -1;
                minOp+=(v[i]-v[median])/x;
            }
        }
        
        
        return minOp;
    }
};
