#include<bits/stdc++.h>
using namespace std;
 
class Graph{

   int v;
   list<int> *l;
   int mod=1e9+7;

public:

	Graph(int v){
		this->v=v;
		l=new list<int>[v];
	}


  void addEdge(int x,int y){
    l[x].push_back(y);
  }

    bool dfs(int node,vector<bool>&visited,vector<bool>&stack){
     
     visited[node]=true;
     stack[node]=true;

     for(auto nbr:l[node]){

       if(!visited[nbr] && dfs(nbr,visited,stack)){
       	 	return true;
       }

       else if(stack[nbr]==true){
       	return true;
       }

     }
     
     stack[node]=false;
     return false;

    }


    bool containsCycle(){
       
       vector<bool> visited(v,false);
       vector<bool> stack(v,false);

       for(int i=0;i<v;i++){
            
            if(!visited[i] && dfs(i,visited,stack)){
              return true;
            }

       }

       return false;

    }


    
    int  toposort(){

     vector<int> indegree(v,0);

     for(int i=0;i<v;i++){
     	for(auto nbr:l[i]){
     		indegree[nbr]+=1;
     	}
     }
      
     queue<int> q;
     
     for(int i=0;i<v;i++){

     	 if(indegree[i]==0){
     	 	q.push(i);
     	 }
     } 

     vector<int> ans;


    while(!q.empty()){
     
      int node=q.front();
      ans.push_back(node);
      q.pop();

      for(auto nbr:l[node]){
      	indegree[nbr]-=1;
      	if(indegree[nbr]==0){
      		q.push(nbr);
      	}
      }


    }

   vector<int> dist(v,0);
  
   dist[0]=1;
   
   for(int i=0;i<v;i++){
       int x=ans[i];
       for(auto nbr:l[x]){
        dist[nbr]=(dist[nbr]+dist[x])%mod;
       }

   }
  
  return dist[v-1];


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

while(m--){

	int a,b;
	cin>>a>>b;
  g.addEdge(a-1,b-1);

}

if(g.containsCycle())
	cout<<"IMPOSSIBLE"<<endl;
else
    cout<<g.toposort()<<endl;


}