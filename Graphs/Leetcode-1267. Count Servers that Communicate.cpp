class Dsu{
  public:
    
    int * parent;
    int * rank;
    int vx;
    
    Dsu(int v){
        vx=v;
        parent=new int[v];
        rank=new int[v];
        
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    
    int findSet(int i){
        if(parent[i]==-1)
            return i;
        return parent[i]=findSet(parent[i]);
    }
    
    void unite(int a,int b){
        
        int s1=findSet(a);
        int s2=findSet(b);
        
        if(s1==s2)
            return;
        
        if(rank[s1]<rank[s2]){
            rank[s2]+=rank[s1];
            parent[s1]=s2;
        }
        else{
            rank[s1]+=rank[s2];
            parent[s2]=s1;
        }
        
    }
    
    
    int countServers(){
        
        int cnt=0;
        
        for(int i=0;i<vx;i++){
            if(parent[i]==-1 and rank[i]>1)
                cnt+=rank[i];
        }
        
        return cnt;
    }
  
    
};


class Solution {
public:
 
    
    int countServers(vector<vector<int>>& grid) {
        
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        Dsu s(n*m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(grid[i][j]==1){
              for(int k=0;k<n;k++)
                  if(grid[k][j]==1)
                     s.unite(i*m+j,k*m+j);
              for(int l=0;l<m;l++)
                  if(grid[i][l]==1)
                    s.unite(i*m+j,i*m+l);
               } 
            }
         }
     
        return s.countServers();
    }
};
