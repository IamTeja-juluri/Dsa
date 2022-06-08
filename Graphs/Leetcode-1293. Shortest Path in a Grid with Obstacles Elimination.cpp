class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
     
        queue<pair<int,pair<int,int> > > q;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        vector<vector<vector<bool> > > visited;
        visited.resize(n,vector<vector<bool> >(m,vector<bool>(k+1,false)));
        
        q.push({k,{0,0}});
        int steps=0;
        
        while(!q.empty()){
            int size=q.size();
            while(size-- > 0){
            auto p=q.front();
            int newk=p.first;
            int x=p.second.first;
            int y=p.second.second;  
            if(x==n-1 && y==m-1)
                return steps;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 &&  newx<n &&  newy>=0 && newy<m){
                    if(grid[newx][newy]==0 && !visited[newx][newy][newk]){
                      q.push({newk,{newx,newy}});
                      visited[newx][newy][newk]=true;
                   }
                   else if(newk>0 && grid[newx][newy]==1 && !visited[newx][newy][newk-1]){
                       q.push({newk-1,{newx,newy}});
                      visited[newx][newy][newk-1]=true;
                   }
                }
            }
        }
         steps+=1;       
     }
        
        return -1;
    }
};
