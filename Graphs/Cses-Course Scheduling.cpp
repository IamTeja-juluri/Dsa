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

	void addEdge(int x,int y){
		l[x].push_back(y);
	}

  bool dfs(int node,vector<bool>&visited,vector<bool>&stack){
     
     stack[node]=true;
     visited[node]=true;

     for(auto nbr:l[node]){
       
        if(!visited[nbr]){
          bool nbrfound=dfs(nbr,visited,stack);
          if(nbrfound){
            return true;
          }
        }
        else if(stack[nbr]==true){
          return true;
        }

     }
    
    stack[node]=false;

    return false;
  }


 bool containscycle(){
        
        vector<bool> visited(v,false);
        vector<bool> stack(v,false);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(dfs(i,visited,stack)){
                    return true;
                }
            }
        }
        
        return false;
    }

    
    void topologicalSort(){
   
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
   
   while(!q.empty()){
        
        int node=q.front();
        q.pop();
        cout<<node+1<<" ";

        for(auto nbr:l[node]){
        	indegree[nbr]-=1;
        	if(indegree[nbr]==0){
        		q.push(nbr);
        	}
        }

   }

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
    
   bool res=g.containscycle();

   if(!res) 
   g.topologicalSort();
   else
    cout<<"IMPOSSIBLE"<<endl;
   
   
  
}