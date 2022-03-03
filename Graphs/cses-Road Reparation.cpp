// Kruskals algorithm
//used for finding minimum spanning tree
//connect all components based on their cost(low cost)
// make sure cycle is not created as we need mst
//implemented using dsu
//path compression and union by rank


#include<bits/stdc++.h>
using namespace std;

class Dsu{
   
   int *parent;
   int* rank;

public:

	 Dsu(int n){
       
       parent=new int[n];
       rank=new int[n];

       for(int i=0;i<n;i++){
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
    

    void unite(int x,int y){

    	int s1=find(x);
    	int s2=find(y);

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

    void addEdge(int x,int y,int wt){
    	edgelist.push_back({wt,x,y});
    }

    int Kruskals_algo(){
        
        int mincost=0;
        
        sort(edgelist.begin(),edgelist.end());
         Dsu s(v);

        for(auto edge:edgelist){
             
             int wt=edge[0];
             int x=edge[1];
             int y=edge[2];

             if(s.find(x)!=s.find(y)){
             	s.unite(x,y);
             	mincost+=wt;
             }


        }

        return mincost;
    }


};


int main(){

	#ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif 

	int n,m;
	cin>>n>>m;
    
    Graph g(n);

   for(int i=0;i<m;i++){
   	int x,y,z;
    cin>>x>>y>>z;
    g.addEdge(x,y,z);

   }

  int mst=g.Kruskals_algo();
  
  if(n-1 == m){
  	cout<<mst<<endl;
  }
  else{
  	cout<<"IMPOSSIBLE"<<endl;
  }
 
  


   
}