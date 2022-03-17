#include<bits/stdc++.h>
using namespace std;
class DSU{
  public:
    
    int *parent;
    int *rank;
    
    DSU(int v){
        
        parent=new int[v];
        rank=new int[v];
        
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    
    int find(int i){
        if(parent[i]==-1)
            return i;
        return parent[i]=find(parent[i]);
    }
    
    void unite(int x,int y,int s1,int s2){
    
        
            if(rank[s1]<rank[s2]){
                rank[s2]+=rank[s1];
                parent[s1]=s2;
            }
            else{
                rank[s1]+=rank[s2];
                parent[s2]=s1;
            }
  
      }
    
};


int main(){
    
    int n,m;
    cin>>n>>m;
    
    DSU s(n);
   
    vector<pair<int,pair<int,int>> >edgelist;

    while(m--){
        
        int x,y,wt;
        cin>>x>>y>>wt;
        
        edgelist.push_back({wt,{x,y}});
    }
    
        int mincost=0;
        sort(edgelist.begin(),edgelist.end());
        
        for(auto edge:edgelist){
            
            int wt=edge.first;
            int x=edge.second.first;
            int y=edge.second.second;
            
            int s1=s.find(x);
            int s2=s.find(y);
            
            if(s1!=s2){
                mincost+=wt;
                s.unite(x,y,s1,s2);
            }
            
        } 
    
    
     cout<<mincost<<endl;
}
