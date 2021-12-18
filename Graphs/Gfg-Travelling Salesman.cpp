//Minimum cost for a round trip
//Np hard Problem

// Brute Force
#include<bits/stdc++.h>
using namespace std;

   int n=4;
    
    int dist[4][4]={
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0},
    };
    
    int visited_all=(1<<n)-1;
    
    int tsp(int mask,int pos){
        
        if(mask==visited_all){
            return dist[pos][0];
        }
        
        int ans=INT_MAX;
        
        for(int city=0;city<n;city++){
            
            if((mask&(1<<city))==0){
                
            int newAns=dist[pos][city]+tsp(mask|(1<<city),city);
            ans=min(ans,newAns);
                
            }
            
            
        }
        return ans;
        
    }
    
    

int main(){
    
  
    cout<<tsp(1,0)<<endl;
    
    
}




//Optimal Memoization approach
    
class Solution {
public:

int tsp(vector<vector<int> > cost,int visitedall,int city,int n,vector<vector<int> > &dp){
    
    if(visitedall==(1<<n)-1){
        return cost[city][0];
    }
    
    if(dp[visitedall][city]!=-1){
        return dp[visitedall][city];
    }
    
    int ans=INT_MAX;
    
    for(int nbr=0;nbr<n;nbr++){
        
        if((visitedall&(1<<nbr))==0){
            
            int currpathsum=cost[city][nbr]+tsp(cost,(visitedall|(1<<nbr)),nbr,n,dp);
            ans=min(ans,currpathsum);
        }
    }
    
    return dp[visitedall][city]=ans;
    
}


int total_cost(vector<vector<int>>cost){
    
    int n=cost.size();
    
    vector<vector<int> > dp(1<<n,vector<int>(n,-1));
    
    return tsp(cost,1,0,n,dp);
    
}
};
        
      
