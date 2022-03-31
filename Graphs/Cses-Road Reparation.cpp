#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
class Dsu{
    
  public:
 
  int *parent,*rank;
  
  Dsu(int v){
      parent=new int[v];
      rank=new int[v];
      for(int i=0;i<v;i++){
          parent[i]=-1;
          rank[i]=1;
      }
  }
  
  int find(int i){
      if(parent[i]==-1){
          return i;
      }
      return parent[i]=find(parent[i]);
  }
  
  void unite(int s1,int s2){
      
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
   
   Dsu s(n);
   
   vector<pair<int,pair<int,int> > >edgelist;
   
   while(m--){
     int x,y,wt;
     cin>>x>>y>>wt;
     edgelist.push_back({wt,{x-1,y-1}});
   }
   
    sort(edgelist.begin(),edgelist.end());
    
    long long mincost=0;
    int edgecount=0;
    
    for(auto edge:edgelist){
      
      int wt=edge.first;
      int x=edge.second.first;
      int y=edge.second.second;
      
      int s1=s.find(x);
      int s2=s.find(y);
      
      if(s1!=s2){
          edgecount+=1;
          long long int wt1=(long long int)(wt);
          mincost=(mincost+wt1);
          s.unite(s1,s2);
      }
          
    }
    
    if(edgecount==(n-1))
    cout<<mincost<<endl;
    else
    cout<<"IMPOSSIBLE"<<endl;
    
}
