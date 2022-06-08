class Solution {
public:
    // remember dis approach
    int minimumObstacles(vector<vector<int>>& grid) {
        
        queue<pair<int,int> >q;
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int> > dist(n,vector<int>(m,INT_MAX));
        
        if(grid[0][0]==1)
            dist[0][0]=1;
        else
            dist[0][0]=0;
        q.push({0,0});
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newx<n && newy>=0 && newy<m){
                    if(dist[newx][newy]>dist[x][y]+grid[x][y]){
                        dist[newx][newy]=dist[x][y]+grid[x][y];
                        q.push({newx,newy});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};
