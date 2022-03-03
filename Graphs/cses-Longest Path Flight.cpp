#include<bits/stdc++.h>
using namespace std;

class Graph{

   int v;
   list<int> *l;

public:

	Graph(int v){
		this->v=v;
		l=new list<int>[v];
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


    
    void toposort(){

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
      ans.push_back(node+1);
      q.pop();

      for(auto nbr:l[node]){
      	indegree[nbr]-=1;
      	if(indegree[nbr]==0){
      		q.push(nbr);
      	}
      }


    }

   vector<int> dist(v,0);
   vector<int> par(v,-1);
   
   dist[0]=1;

   vector<bool> visited(v,false);
    vector<bool> stack(v,false);

    dfs(i,visited,stack);



 }



};

int main(){
 
 int n,m; 
cin>>n>>m;

while(m--){

	int a,b;
	cin>>a>>b;
    g.addEdge(a-1,b-1);

}

if(g.containsCycle())
	cout<<"IMPOSSIBLE"<<endl;
else
    g.toposort();


}