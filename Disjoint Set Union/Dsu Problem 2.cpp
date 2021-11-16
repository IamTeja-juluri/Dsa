
/*
Budget Padmanabham planned to visit the tourist places.
There are N tourist places in the city.
The tourist places are numbered from 1 to N.
You are given the routes[] to travel between the tourist places in the city.
where routes[i]=[place-1, place-2, price], A route is a bi-directional route.
You can travel from place-1 to place-2 or place-2 to place-1 with the given price.
 
Your task is to help Budget Padmanabham to find the cheapest route plan,
to visit all the tourist places in the city. If you are not able to find such plan, print -1.
 
Input Format:
-------------
Line-1: Two space separated integers N and R,number of places and routes.
Next R lines: Three space separated integers, start, end and price.
  
Output Format:
--------------
Print an integer, minimum cost to visit all the tourist places.
 
 
Sample Input-1:
---------------
4 5
1 2 3
1 3 5
2 3 4
3 4 1
2 4 5
 
Sample Output-1:
----------------
8
 
Explanation:
------------
The cheapest route plan is as follows:
 1-2, 2-3, 3-4 and cost is 3 + 4 + 1 = 8
 
 
Sample Input-2:
---------------
4 3
1 2 3
1 3 5
2 3 4
 
Sample Output-2:
----------------
-1
*/
#include<bits/stdc++.h>
using namespace std;

class DSU{
    
    int *parent;
    int *rank;
    
    public:
    
    DSU(int n){
        
        parent=new int[n];
        rank=new int[n];
        
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        
    }
    
    int findSet(int i){
        
        if(parent[i]==-1){
          return i;  
        }
        
        return parent[i]=findSet(parent[i]);
    }
  
  void unite(int x,int y){
      
      int s1=findSet(x);
      int s2=findSet(y);
      
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
      
  }
  
    
};

class Graph{
  
  int v;
  vector<vector<int> > edgelist;
  
  public:
  
  Graph(int v){
      this->v=v;
  }
  
  void addEdge(int x,int y,int w){
      edgelist.push_back({w,x,y});
  }
  
  int kruskal(){
      
      sort(edgelist.begin(),edgelist.end());
      
      DSU s(v);
      
      int ans=0;
      
      for(auto edge:edgelist){
          
          int w=edge[0];
          int x=edge[1];
          int y=edge[2];
          
          if(s.findSet(x)!=s.findSet(y)){
              s.unite(x,y);
              ans+=w;
          }
          
          
      }
      
      return ans;
  }
  
  
};


int main(){
   
    int n,r;
    cin>>n>>r;
    
    if(n>r){
        cout<<-1<<endl;
        return 0;
    }
    
    
    Graph g(n);
    
    while(r--){
      
      int x,y,w;
      cin>>x>>y>>w;
      g.addEdge(x-1,y-1,w);
      
    }
    
    cout<<g.kruskal()<<endl; 
    
    
}
