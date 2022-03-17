//kruskals algo
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
//prims algo
#include<bits/stdc++.h>
using namespace std;

class Graph{
  
  vector<pair<int,int>> *l;
  int v;
  
  public:
  
  Graph(int n){
      v=n;
      l=new vector<pair<int,int>>[n];
  }
  
  void addEdge(int x,int y,int w){
      l[x].push_back({y,w});
      l[y].push_back({x,w});
  }
  
  
  int prims_algo(){
      
      priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>>q;
      
      bool *visited=new bool[v]{false};
      int ans=0;
      
      q.push({0,0});
      
      while(!q.empty()){
          
          auto curr=q.top();
          q.pop();
          
          int dest=curr.second;
          int weight=curr.first;
          
          if(visited[dest]==true)
          continue;
          
          ans+=weight;
          visited[dest]=true;
          
          for(auto x:l[dest]){
              if(visited[x.first]==false){
                  q.push({x.second,x.first});
              }
          }
          
      }
      
      return ans;
      
  }
    
    
};

int main(){
    
    int n,m;
    cin>>n>>m;
    
    Graph g(n);
    
    for(int i=0;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    
    cout<<g.prims_algo()<<endl;
    
}
