#include<bits/stdc++.h>
using namespace std;
class Graph{

  int v;
  list<int> *l;
  
public:

	Graph(int v){
		this->v=v;
		list=new list<int> l[v];
	}
    
    void topodfs(int node,vector<bool>&visited,vector<int>&ans){

      visited[node]=true;

      for(auto nbr:l[node]){
      	if(!visited[nbr]){
      		dfs(nbr,visited);
      	}
      }

     ans.push_back(node);
     return ;

    }
    
    void toposort(){

       vector<vector<int> > res;

       for(auto nbr:l[0]){
       	
       	vector<int> ans;
       	vector<bool>visited;
       	dfs(nbr,visited,ans);
       	reverse(ans.begin(),ans.end());
       	res.push_back(ans);

       }

    }
    


};


int main(){

}