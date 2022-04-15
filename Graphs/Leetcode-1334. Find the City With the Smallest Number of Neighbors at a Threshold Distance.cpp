class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k1) {
        
        int maxN=1e9;
        vector<vector<int> > dist(n+1,vector<int>(n+1,maxN));
        
        for(int i=0;i<n;i++)
            dist[i][i]=0;
        
        
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            int wt=edges[i][2];
            dist[x][y]=wt;
            dist[y][x]=wt;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        
        int mincities=INT_MAX;
        int city=0;
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=k1)
                    count+=1;
            }
            
            if(mincities>=count){
                mincities=count;
                city=i;
            }
        }
        
        return city;
    }
};
