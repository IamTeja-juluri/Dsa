#include<bits/stdc++.h>
using namespace std;

class Graph{
    
    public:

    	int v;
    	list<int>*l;
        vector<int> dp;

    	Graph(int v){
    		this->v=v;
    		l=new list<int>[v];
    		dp.resize(v,-1);
    	}

    	void addEdge(int x,int y){
    		l[y].push_back(x);
    	}
        
        int longestPath(int node){

        	if(dp[node]!=-1)
        		return dp[node];

           int ans=0;
           bool leaf=1;

          for(auto nbr:l[node]){
            leaf=0;
            ans=max(ans,longestPath(nbr));
        }

         return dp[node]=leaf?0:1+ans;
       }

};


int main(){

	#ifndef ONLINE_JUDGE
	  freopen("inputgr.txt","r",stdin);
	  freopen("outputgr.txt","w",stdout);
	#endif

   
   int n,m;
   cin>>n>>m;

   Graph g(n);

   while(m--){
    int x,y;
    cin>>x>>y;
    g.addEdge(x-1,y-1);
   }

   
   int ans=0;

   for(int i=0;i<n;i++)
      ans=max(ans,g.longestPath(i));
   
    cout<<ans<<endl;
    
}