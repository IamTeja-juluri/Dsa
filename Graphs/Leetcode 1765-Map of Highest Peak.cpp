class Solution {
public:
    vector<vector<int> > highestPeak(vector<vector<int>>& mat) {
     
        vector<vector<int> > dist;
        //multi source bfs example
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        queue<pair<int,int> > q;
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=INT_MAX;
                if(mat[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            
            for(int i=0;i<4;i++){
                
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<n && newy>=0 && newy<m && dist[newx][newy]==INT_MAX){
                    dist[newx][newy]=dist[x][y]+1;
                    q.push({newx,newy});
                }
                
                
            }
            
            
        }
        
        
        
        return dist;
    }
};
