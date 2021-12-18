//Atcoder DP educational DP contest
//Recursive
#include<bits/stdc++.h>
using namespace std;

int mincost(int v[],int n,int idx){
    
    if(idx==n-1)
    return 0;
    
    if(idx==n-2){
        return abs(v[idx]-v[idx+1]);
    }
    
     int l=INT_MAX;
     int r=INT_MAX;

        
    l=abs(v[idx]-v[idx+1])+mincost(v,n,idx+1);
    r=abs(v[idx]-v[idx+2])+mincost(v,n,idx+2);
    
      
    return min(l,r);
    
}

int main()
{
    
    int n;
    cin>>n;
   
    int v[n];
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
     cout<<mincost(v,n,0);
    
    

    return 0;
}

//Memoization -1

#include<bits/stdc++.h>
using namespace std;


int mincost(int v[],int n,int idx,vector<int> &dp){
    
    if(idx==n-1)
    return dp[idx]=0;
    
    
    if(dp[idx]!=-1){
        return dp[idx];
    }
    
    if(idx==n-2){
        return dp[idx]=abs(v[idx]-v[idx+1]);
    }
    
     int l=INT_MAX;
     int r=INT_MAX;

        
    l=abs(v[idx]-v[idx+1])+mincost(v,n,idx+1,dp);
    r=abs(v[idx]-v[idx+2])+mincost(v,n,idx+2,dp);
    
      
    return dp[idx]=min(l,r);
    
}

int main()
{
    
    int n;
    cin>>n;
   
    int v[n];
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
     vector<int> dp(n,-1);
    
     cout<<mincost(v,n,0,dp);
    
    

    return 0;
}


//Memoization 2

#include<bits/stdc++.h>
using namespace std;


int mincost(int v[],int n,vector<int> &dp){
    
    if(n==0)
    return dp[n]=0;
    
    
    if(dp[n]!=-1){
        return dp[n];
    }
    
    if(n==1){
        return dp[n]=abs(v[n]-v[n-1]);
    }
    
     int l=INT_MAX;
     int r=INT_MAX;

        
    l=abs(v[n]-v[n-1])+mincost(v,n-1,dp);
    r=abs(v[n]-v[n-2])+mincost(v,n-2,dp);
    
      
    return dp[n]=min(l,r);
    
}

int main()
{
    
    int n;
    cin>>n;
   
    int v[n];
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
     vector<int> dp(n,-1);
    
     cout<<mincost(v,n-1,dp);
    
    

    return 0;
}

//Tabulation
#include<bits/stdc++.h>
using namespace std;

int mincost(int v[],int n){
  
    vector<int> dp(n,0);
    
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    
    
   for(int i=2;i<n;i++){
        
   int l=abs(v[i]-v[i-1])+dp[i-1];
   int r=abs(v[i]-v[i-2])+dp[i-2];
    
    dp[i]=min(l,r);
        
    }
        
  
    return dp[n-1];
   
    
}

int main()
{
    
    int n;
    cin>>n;
   
    int v[n];
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
     
     cout<<mincost(v,n);
    
    

    return 0;
}

