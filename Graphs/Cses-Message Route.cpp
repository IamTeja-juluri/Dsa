#include<bits/stdc++.h>
using namespace std;
 
 int v;
 vector<int>gr[100001];
    void shortestPath(){
      
      queue<int>q;
      q.push(1);
      vector<int>visited(v+1,0);
      visited[1]=-1;
      
      while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto nbr:gr[node]){
              if(!visited[nbr]){
                  visited[nbr]=node;
                  q.push(nbr);
              }
          }
      }
      
      int loc=v;
      vector<int>ans;
      
      while(visited[loc] && visited[loc]!=-1){
          ans.push_back(visited[loc]);
          loc=visited[loc];
      }
      
      if(size(ans)){
          cout<<size(ans)+1<<endl;
          reverse(ans.begin(),ans.end());
          for(auto x:ans)
          cout<<x<<" ";
          cout<<v<<endl;
      }
      else
       cout<<"IMPOSSIBLE"<<endl;
      
  }
   
  
 

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("inputgr.txt","r",stdin);
    freopen("outputgr.txt","w",stdout);
    #endif
    
    int n,m;
    cin>>n>>m;
    
    v=n;
    
    for(int i=0;i<m;i++){   
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    shortestPath();
}
