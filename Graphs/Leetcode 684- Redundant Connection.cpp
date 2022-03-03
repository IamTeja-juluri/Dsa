//Using Dsu
class Graph{
     
    int v;
    int *parent;
    int *rank;
    
    public:
    
    Graph(int v){
        
        this->v=v;
        parent=new int[v];
        rank=new int[v];
        
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }    
    }
    
     int findset(int i){
        
        if(parent[i]==-1){
            return i;
        }
        
        return parent[i]=findset(parent[i]);
        
     }
    
    vector<int> redundant(vector<vector<int> > &edges){
        
        vector<vector<int> > res;
        
        int n=edges.size();
        
        for(int r=0;r<n;r++){
            
            int i=edges[r][0]-1;
            int j=edges[r][1]-1;
            
            int s1=findset(i);
            int s2=findset(j);
            
            if(s1!=s2){
                
                if(rank[s1]<rank[s2]){
                    rank[s2]+=rank[s1];
                    parent[s1]=s2;
                }
                else{
                    rank[s1]+=rank[s2];
                    parent[s2]=s1;
                }
                
            }
             else{
                
                    vector<int> v;
                    v.push_back(i+1);
                    v.push_back(j+1);
                    res.push_back(v);
                
               }
            
           }
        
              int z=res.size();
        
              vector<int> ans;
        
              if(z==0)
               return ans;
               
        
             return res[z-1];
        
        
    }
    
    
};


class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        
        Graph g(n);
        
        vector<int> ans=g.redundant(edges);
        
        return ans;
        
    }
};