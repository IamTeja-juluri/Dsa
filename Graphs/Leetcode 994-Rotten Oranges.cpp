class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
       int dx[]={1,-1,0,0};
       int dy[]={0,0,1,-1};
       
       int n=grid.size();
       int m=grid[0].size();
        
       queue<pair<int,int> > q;
        
       vector<vector<int > > dist;
        
        
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    v.push_back(0);
                }
                else if(grid[i][j]==1){
                    v.push_back(0);
                }
                else{
                    v.push_back(INT_MAX);
                }
            }
            dist.push_back(v);
        }
        
       
        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]!=0 && grid[newx][newy]!=2){
                    grid[newx][newy]=2;
                    q.push({newx,newy});
                    dist[newx][newy]=dist[x][y]+1;
                }
                
            }
            
        }
        
        int no=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                else if(dist[i][j]!=INT_MAX){
                   no=max(no,dist[i][j]); 
                }
            }
        }
        
       return no;
    }
};
