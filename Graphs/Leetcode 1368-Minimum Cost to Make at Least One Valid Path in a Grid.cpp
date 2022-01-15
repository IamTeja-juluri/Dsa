//bfs
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
       
        int n=grid.size();
        int m=grid[0].size();
        
        if(n==0){
            return 0;
        }
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
       vector<vector<int> > dist(n,vector<int> (m,INT_MAX));
       
       queue<pair<int,int> > q;
        
       dist[0][0]=0;
       
       q.push({0,0});
        
       while(!q.empty()){

           int x=q.front().first;
           int y=q.front().second;
           
           q.pop();
           
           for(int i=0;i<4;i++){
               
              int newx=x+dx[i];
              int newy=y+dy[i];
               
               if(newx>=0 && newx<n && newy>=0 && newy<m ){
                   
                   if(i+1 == grid[x][y] && dist[newx][newy]>dist[x][y]){
                       q.push({newx,newy});
                       dist[newx][newy]=dist[x][y];
                   }
                   else if(dist[x][y]+1<dist[newx][newy]){
                       q.push({newx,newy});
                       dist[newx][newy]=dist[x][y]+1;
                   }
                   
               }
               
               
           }
           
       } 
        
        return dist[n-1][m-1];
    }
};
