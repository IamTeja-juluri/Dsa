//Multisrc bfs

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        
        queue<pair<int,int> > q;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int> > dist(n,vector<int>(m,INT_MAX));

        bool flag=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
                else
                    flag=true;
            }
        }
        
        if(flag==false)
            return -1;
        
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        while(!q.empty()){
          
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<n && newy>=0 && newy<m  && dist[newx][newy]>(dist[x][y]+1)){
                    q.push({newx,newy});
                    dist[newx][newy]=dist[x][y]+1;
                }
            }
            
        }
        
        int ans=-1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dist[i][j]!=INT_MAX)
                    ans=max(ans,dist[i][j]);
            }
        }
        
        return ans;
        
    }
};
