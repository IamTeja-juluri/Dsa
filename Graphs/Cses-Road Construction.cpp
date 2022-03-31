#include<bits/stdc++.h>
using namespace std;
class Dsu{
    
  public:
  int *parent;
  int *rank;
  
  Dsu(int v){
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
  
  int unite(int s1,int s2){
      
      if(rank[s1]<rank[s2]){
          rank[s2]+=rank[s1];
          parent[s1]=s2;
      }
      else{
          rank[s1]+=rank[s2];
          parent[s2]=s1;
      }
      
      return max(rank[s1],rank[s2]);
  }
    
};

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("inputgr.txt","r",stdin);
    freopen("outputgr.txt","w",stdout);
    #endif
    
    int n,m;
    cin>>n>>m;
    
    Dsu s(n);
    int maxi=0;
    int components=n;
    
    while(m--){
        int x,y;
        cin>>x>>y;
        int s1=s.find(x-1);
        int s2=s.find(y-1);
        if(s1!=s2){
            components-=1;
            maxi=max(maxi,s.unite(s1,s2));
        }
        cout<<components<<" "<<maxi<<endl;
    }
    
    
    
}
