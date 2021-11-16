//Union by rank and Path compression
#include<bits/stdc++.h>
using namespace std;

class Graph{
    
  int v;
  list<pair<int,int> > l;
  
  public:
  
  Graph(int v){
      this->v=v;
  }
  
  int addEdge(int u,int v){
      l.push_back({u,v});
  }
  
  //Path Compression Optimisation -Find function
  int findSet(int i,int parent[]){
      
      if(parent[i]==-1){
          return i;
      }
      
      return parent[i]=findSet(parent[i],parent);
      
  }
  
  //union by rank
  void union_set(int x,int y,int parent[],int rank[]){
      
      
      
      int s1=findSet(x,parent);
      int s2=findSet(y,parent);
      
      if(s1!=s2){
          
          if(rank[s1]<rank[s2]){
            parent[s1]=s2;
            rank[s2]+=rank[s1];
          }
          
          else{
              parent[s2]=s1;
              rank[s1]+=rank[s2];
          }
         
      }
      
      
  }
  
  //Cycle Detection in undirected graph using dsu
  
  bool contains_cycle(){
      
      int *parent=new int[v];
      int *rank=new int[v];
      
      for (int i=0;i<v;i++) {
          parent[i]=-1;
          rank[i]=1;
      }
      
      for(auto edge:l){
          
          int i=edge.first;
          int j=edge.second;
          
          int s1=findSet(i,parent);
          int s2=findSet(j,parent);
          
          if(s1!=s2){
              union_set(s1,s2,parent,rank);
          }
          else{
             
             // return true;
          }
          
      }
      
      for(int i=0;i<v;i++){
          cout<<parent[i]<<" ";
      }
      cout<<endl;
      for(int i=0;i<v;i++){
          cout<<rank[i]<<" ";
      }
       cout<<endl;
      delete [] parent;
      delete [] rank;
      return false;
      
  }
  
 
    
};

int main(){
    
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(2,5);
 //   g.addEdge(2,6); 
    
    cout<<g.contains_cycle();
    
}





