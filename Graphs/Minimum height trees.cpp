//Gives Tle
#include<bits/stdc++.h>
using namespace std;

int bfs(int n,int src,vector<int> gr[]){
        
   queue<int> q;

   vector<bool> visited(n,false);
   vector<int> dist(n,INT_MAX);
        
    dist[src]=0;
        
    q.push(src);
    visited[src]=true;
    int ans=0;
        
    while(!q.empty()){
            
    int node=q.front();
    q.pop();
            
    for(auto nbr:gr[node]){
                
        if(!visited[nbr]){
            dist[nbr]=dist[node]+1;
            ans=max(ans,dist[nbr]);
            visited[nbr]=true;
            q.push(nbr);
         }
                
       }
            
    }
        
  return ans;
        
}
    
int main(){

  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif 

   int n;
   
   cin>>n;
   
   int m=n-1;
   
   vector<int> gr[n];
   
   for(int i=0;i<m;i++){
       
       int x,y;
       cin>>x>>y;
       gr[x].push_back(y);
       gr[y].push_back(x);
       
   }
   
        int height=INT_MAX;
        
        vector<pair<int,int> > vp;
        
        for(int i=0;i<n;i++){
            
            int ans=bfs(n,i,gr);
            height=min(ans,height);
            vp.push_back({i,ans});
            
        }
        
     
        vector<int> res;
        
        for(int i=0;i<vp.size();i++){
            
            int x=vp[i].first;
            int y=vp[i].second;
            
            if(y==height){
                res.push_back(x);
            }
            
        }
        
        sort(res.begin(),res.end());
        
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
         
}
 // Optimal approach

// refer youtube
// Important Observation is that there can be atmost 2 minimum height trees because
// only the middle elements of a tree contributes to the minimum height trees



class Solution {
public:
    
   
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        int m=edges.size();
         vector<int> res;
         res.push_back(0);
        if(m==0 || n==1)
            return res;
        
        res.pop_back();
        
        vector<int> gr[n];
        vector<int> indegree(n,0);
        
        for(auto edge:edges){
            
            int x=edge[0];
            int y=edge[1];
            
            indegree[x]+=1;
            indegree[y]+=1;
            gr[x].push_back(y);
            gr[y].push_back(x);
            
        }
        
        queue<int> q;
       
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        
        
        
          while(n>2){
              
              int size=q.size();
              n=n-size;
              
              for(int i=1;i<=size;i++){
                   
                  int node=q.front();
                   q.pop();
                  for(auto nbr:gr[node]){
                      indegree[nbr]-=1;
                      if(indegree[nbr]==1){
                          q.push(nbr);
                      }
                  }
                  
              }
              
         }  
        
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};