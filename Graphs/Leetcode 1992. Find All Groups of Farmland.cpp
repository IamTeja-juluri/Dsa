class Solution {
public:
    
    int x1,y1;
    int x2,y2;
    
    void dfs(int x,int y,vector<vector<int> > &land,vector<vector<bool> > &visited){
        
        x1=min(x1,x);
        y1=min(y1,y);
        
        x2=max(x2,x);
        y2=max(y2,y);
        
        visited[x][y]=true;
        
        int n=land.size();
        int m=land[0].size();
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && land[newx][newy]==1 && visited[newx][newy]==false){
                
                dfs(newx,newy,land,visited);
                
            }
            
            
        }
        
        
    }
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
       
        int n=land.size();
        int m=land[0].size();
        
        vector<vector<bool > > visited(n,vector<bool>(m,false));
        vector<vector<int> > v;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 x1=INT_MAX,y1=INT_MAX;
                 x2=INT_MIN,y2=INT_MIN;
                if(!visited[i][j] && land[i][j]==1){
                    dfs(i,j,land,visited);
                    vector<int> res;
                     res.push_back(x1);
                     res.push_back(y1);
                     res.push_back(x2);
                     res.push_back(y2); 
                     v.push_back(res);
                }
                
            }
        }
        
                   
        return v;
        
    }
};